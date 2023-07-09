//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_SETCOMMAND_H
#define CPP_REDIS_LIKE_SETCOMMAND_H


#include "Command.h"

class SetCommand : public Command {
public:
    std::unique_ptr<RespType> execute() override;

    explicit SetCommand(std::vector<std::string> args) : Command(std::move(args)) {}

    ~SetCommand() override = default;
};


#endif //CPP_REDIS_LIKE_SETCOMMAND_H
