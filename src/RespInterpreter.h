//
// Created by gouil on 08/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPINTERPRETER_H
#define CPP_REDIS_LIKE_RESPINTERPRETER_H


#include <string>
#include <utility>
#include <memory>
#include "commands/Command.h"
#include "commands/PingCommand.h"

class RespInterpreter {
private:
    std::string command;

public:
    explicit RespInterpreter(std::string command) : command(std::move(command)) {}

    std::unique_ptr<Command> getCommandHandler();
};


#endif //CPP_REDIS_LIKE_RESPINTERPRETER_H
