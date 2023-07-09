//
// Created by gouil on 08/07/2023.
//

#ifndef CPP_REDIS_LIKE_UNKNOWNCOMMAND_H
#define CPP_REDIS_LIKE_UNKNOWNCOMMAND_H


#include "Command.h"
#include "../resp_type/RespType.h"

#include <utility>
#include <memory>

class UnknownCommand : public Command {
public:
    std::unique_ptr<RespType> getRespResponse() override;

    explicit UnknownCommand(std::vector<std::string> args) : Command(std::move(args)) {}

    explicit UnknownCommand(const std::string &command) : Command({}) {
        args.push_back(command);
    }

    ~UnknownCommand() override = default;
};


#endif //CPP_REDIS_LIKE_UNKNOWNCOMMAND_H
