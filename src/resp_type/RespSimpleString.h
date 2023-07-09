//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPSIMPLESTRING_H
#define CPP_REDIS_LIKE_RESPSIMPLESTRING_H


#include <utility>

#include "RespType.h"

class RespSimpleString : public RespType {
private:
    std::string value;
public:
    explicit RespSimpleString(std::string value) : RespType(), value(std::move(value)) {}

    inline std::string buildResponse() override {
        return "+" + value + "\r\n";
    }
};


#endif //CPP_REDIS_LIKE_RESPSIMPLESTRING_H
