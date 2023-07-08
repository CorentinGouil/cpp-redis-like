//
// Created by gouil on 23/06/2023.
//

#ifndef CPP_REDIS_LIKE_THREADSTOPPER_H
#define CPP_REDIS_LIKE_THREADSTOPPER_H


#include <atomic>
#include <mutex>

class ThreadStopper {
private:
    ThreadStopper();

    std::atomic<bool> stop = false;

public:
    static ThreadStopper &GetInstance();

    ThreadStopper(ThreadStopper &other) = delete;

    void operator=(const ThreadStopper &) = delete;

    bool shouldStop() { return stop; }

    void setStop(bool b) { this->stop = b; }
};


#endif //CPP_REDIS_LIKE_THREADSTOPPER_H
