//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_GETCOMMAND_H
#define CPP_REDIS_LIKE_GETCOMMAND_H

#include "Command.h"

class GetCommand : public Command {
public:
    std::unique_ptr<RespType> execute() override;

    explicit GetCommand(std::vector<std::string> args) : Command(std::move(args)) {}

    ~GetCommand() override = default;
};


#endif //CPP_REDIS_LIKE_GETCOMMAND_H
