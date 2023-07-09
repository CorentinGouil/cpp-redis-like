cmake_minimum_required(VERSION 3.25)
project(cpp_redis_like)

set(CMAKE_CXX_STANDARD 17)
link_libraries(ws2_32 wsock32)

add_executable(cpp_redis_like src/main.cpp src/RedisServer.cpp src/RedisServer.h src/ThreadStopper.cpp src/ThreadStopper.h src/RespInterpreter.cpp src/RespInterpreter.h src/commands/Command.h src/commands/PingCommand.cpp src/commands/PingCommand.h src/commands/UnknownCommand.cpp src/commands/UnknownCommand.h src/commands/EchoCommand.cpp src/commands/EchoCommand.h src/resp_type/RespType.h src/resp_type/RespSimpleString.h src/resp_type/RespError.h src/resp_type/RespInteger.h src/resp_type/RespBulkString.h src/resp_type/RespArray.cpp src/resp_type/RespArray.h src/commands/SetCommand.cpp src/commands/SetCommand.h src/DataStore.cpp src/DataStore.h src/commands/GetCommand.cpp src/commands/GetCommand.h src/resp_type/RespNull.h)
