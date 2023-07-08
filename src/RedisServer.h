//
// Created by Corentin Gouil on 23/06/2023.
//

#ifndef CPP_REDIS_LIKE_REDISSERVER_H
#define CPP_REDIS_LIKE_REDISSERVER_H

#ifdef _WIN32

#include <winsock.h>

#endif

#include <atomic>
#include <queue>

#include "ThreadStopper.h"

typedef int socklen_t;

class RedisServer {
private:
    unsigned int port;
    unsigned int nbRunners;


    SOCKADDR_IN sin{};
//    SOCKET sock{};
    socklen_t recsize;
    struct timeval timeout{};

    std::queue<SOCKET> connectionQueue;
    std::mutex connectionQueueMutex;

    void connectionRegister(SOCKET sock);

    void connectionHandler();

public:
    explicit RedisServer(unsigned int port, unsigned int nbRunners);

    ~RedisServer() = default;

    void spawnServer();
};


#endif //CPP_REDIS_LIKE_REDISSERVER_H
