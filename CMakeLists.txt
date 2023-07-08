cmake_minimum_required(VERSION 3.25)
project(cpp_redis_like)

set(CMAKE_CXX_STANDARD 17)
link_libraries(ws2_32 wsock32)

add_executable(cpp_redis_like src/main.cpp src/RedisServer.cpp src/RedisServer.h src/ThreadStopper.cpp src/ThreadStopper.h src/RespInterpreter.cpp src/RespInterpreter.h src/commands/Command.cpp src/commands/Command.h src/commands/PingCommand.cpp src/commands/PingCommand.h src/commands/UnknownCommand.cpp src/commands/UnknownCommand.h)
