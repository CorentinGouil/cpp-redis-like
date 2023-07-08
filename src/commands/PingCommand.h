//
// Created by gouil on 08/07/2023.
//

#ifndef CPP_REDIS_LIKE_PINGCOMMAND_H
#define CPP_REDIS_LIKE_PINGCOMMAND_H


#include "Command.h"

#include <utility>

class PingCommand : public Command {
    std::string arg;
public:
    std::string getResponse() override;

    PingCommand() = default;

    explicit PingCommand(std::string arg) : arg(std::move(arg)) {}

    ~PingCommand() override = default;
};


#endif //CPP_REDIS_LIKE_PINGCOMMAND_H
