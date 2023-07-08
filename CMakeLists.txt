cmake_minimum_required(VERSION 3.25)
project(cpp_redis_like)

set(CMAKE_CXX_STANDARD 17)
link_libraries(ws2_32 wsock32)

add_executable(cpp_redis_like main.cpp RedisServer.cpp RedisServer.h ThreadStopper.cpp ThreadStopper.h)
