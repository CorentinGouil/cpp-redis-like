//
// Created by gouil on 08/07/2023.
//

#ifndef CPP_REDIS_LIKE_PINGCOMMAND_H
#define CPP_REDIS_LIKE_PINGCOMMAND_H


#include "Command.h"
#include "../resp_type/RespType.h"

#include <utility>

class PingCommand : public Command {
public:
    std::unique_ptr<RespType> getRespResponse() override;

    explicit PingCommand(std::vector<std::string> args) : Command(std::move(args)) {}

    ~PingCommand() override = default;
};


#endif //CPP_REDIS_LIKE_PINGCOMMAND_H
