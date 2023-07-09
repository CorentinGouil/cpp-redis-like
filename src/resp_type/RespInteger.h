//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPINTEGER_H
#define CPP_REDIS_LIKE_RESPINTEGER_H


#include "RespType.h"

class RespInteger : public RespType {
private:
    int value;
public:
    explicit RespInteger(int value) : RespType(), value(value) {}

    inline std::string buildResponse() override {
        return ":" + std::to_string(value) + "\r\n";
    }
};


#endif //CPP_REDIS_LIKE_RESPINTEGER_H
