//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_ECHOCOMMAND_H
#define CPP_REDIS_LIKE_ECHOCOMMAND_H


#include "Command.h"

class EchoCommand : public Command {
public:
    std::string getResponse() override;

    explicit EchoCommand(std::vector<std::string> args) : Command(std::move(args)) {}

    ~EchoCommand() override = default;
};


#endif //CPP_REDIS_LIKE_ECHOCOMMAND_H
