//
// Created by gouil on 08/07/2023.
//

#ifndef CPP_REDIS_LIKE_COMMAND_H
#define CPP_REDIS_LIKE_COMMAND_H


#include <string>
#include <utility>
#include <vector>
#include <memory>
#include "../resp_type/RespType.h"

class Command {
protected:
    std::vector<std::string> args;
public:
    explicit Command(std::vector<std::string> args) : args(std::move(args)) {}

    virtual std::unique_ptr<RespType> execute() = 0;

    virtual ~Command() = default;
};


#endif //CPP_REDIS_LIKE_COMMAND_H
