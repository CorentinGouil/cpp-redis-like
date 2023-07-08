//
// Created by gouil on 23/06/2023.
//

#include <iostream>
#include "ThreadStopper.h"


void signal_callback_handler(int signum) {
    if (signum != SIGINT) return;

    std::cout << "Shutting down..." << std::endl;

    ThreadStopper &ts = ThreadStopper::GetInstance();
    ts.setStop(true);
//    std::terminate();
}

ThreadStopper::ThreadStopper() {
    signal(SIGINT, signal_callback_handler);
}

ThreadStopper &ThreadStopper::GetInstance() {
    static ThreadStopper inst;
    return inst;
}
