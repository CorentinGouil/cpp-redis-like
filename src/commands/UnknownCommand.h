//
// Created by gouil on 08/07/2023.
//

#ifndef CPP_REDIS_LIKE_UNKNOWNCOMMAND_H
#define CPP_REDIS_LIKE_UNKNOWNCOMMAND_H


#include "Command.h"

class UnknownCommand : public Command {
public:
    std::string getResponse() override;

    explicit UnknownCommand(std::vector<std::string> args) : Command(std::move(args)) {}

    ~UnknownCommand() override = default;
};


#endif //CPP_REDIS_LIKE_UNKNOWNCOMMAND_H
