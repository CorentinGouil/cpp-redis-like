//
// Created by Corentin Gouil on 23/06/2023.
//

#include "RedisServer.h"
#include "RespInterpreter.h"

#ifdef _WIN32

#include <winsock2.h>

#else
#endif

#include <iostream>
#include <thread>
#include <chrono>
#include <list>

#define SLEEP_TIME 1


const char *hello = "+PONG\r\n";

RedisServer::RedisServer(unsigned int port, unsigned int nbRunners) : port(port), nbRunners(nbRunners) {
    recsize = sizeof(sin);

    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_family = AF_INET;
    sin.sin_port = htons(this->port);

    timeout.tv_sec = 0;
    timeout.tv_usec = 200;
}

void RedisServer::connectionRegister(SOCKET sock) {
    ThreadStopper &stop = ThreadStopper::GetInstance();

    while (!stop.shouldStop()) {
        SOCKADDR_IN csin;
        SOCKET csock;
        socklen_t crecsize = sizeof(csin);

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sock, &fds);

        if (select(sock, &fds, nullptr, nullptr, &timeout) <= 0) continue;

        if (!FD_ISSET(sock, &fds)) continue;

        csock = accept(sock, (SOCKADDR *) &csin, &crecsize);

        connectionQueueMutex.lock();
        connectionQueue.push(csock);
        connectionQueueMutex.unlock();
    }
}

void RedisServer::connectionHandler() {
    ThreadStopper &stop = ThreadStopper::GetInstance();

    while (!stop.shouldStop()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));

        if (!connectionQueueMutex.try_lock()) {
            continue;
        }

        if (connectionQueue.empty()) {
            connectionQueueMutex.unlock();
            continue;
        }

        SOCKET csock = connectionQueue.front();
        connectionQueue.pop();
        connectionQueueMutex.unlock();

        char buffer[1024] = {0};
        int read;

        while (!stop.shouldStop()) {
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(csock, &fds);

            if (select(csock, &fds, nullptr, nullptr, &timeout) <= 0) continue;
            if (!FD_ISSET(csock, &fds)) continue;

            read = recv(csock, buffer, 1024, 0);
            if (read < 0) continue;
            if (read == 0) break;

            RespInterpreter respInterpreter((std::string(buffer)));
            std::unique_ptr<Command> command = respInterpreter.getCommandHandler();
            std::unique_ptr<RespType> restResponse = command->getRespResponse();

            std::string response = restResponse->buildResponse();

            send(csock, response.c_str(), (int) response.length(), 0);
        }

        closesocket(csock);
    }
}

void RedisServer::spawnServer() {
#if defined (WIN32)
    WSADATA WSAData;
    int error = WSAStartup(MAKEWORD(2, 2), &WSAData);
    if (error) throw std::exception();
#endif

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        perror("socket");
        return;
    }

    int sock_err = bind(sock, (SOCKADDR *) &sin, recsize);
    if (sock_err == SOCKET_ERROR) {
        perror("bind");
        return;
    }

    sock_err = listen(sock, 5);
    if (sock_err == SOCKET_ERROR) {
        perror("listen");
        return;
    }

    std::list<std::thread *> threads{};
    for (int i = 0; i < nbRunners; i++) {
        auto t = new std::thread(&RedisServer::connectionHandler, this);
        threads.push_back(t);
    }

    connectionRegister(sock);

    for (auto t: threads) {
        t->join();
        delete t;
    }

    closesocket(sock);

#if defined (WIN32)
    WSACleanup();
#endif
}


