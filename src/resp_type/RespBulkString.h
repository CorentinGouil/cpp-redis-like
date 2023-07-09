//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPBULKSTRING_H
#define CPP_REDIS_LIKE_RESPBULKSTRING_H


#include "RespType.h"

class RespBulkString : public RespType {
private:
    std::string value;
public:
    explicit RespBulkString(std::string value) : RespType(), value(std::move(value)) {}

    inline std::string buildResponse() override {
        return "$" + std::to_string(value.length()) + "\r\n" + value + "\r\n";
    }
};


#endif //CPP_REDIS_LIKE_RESPBULKSTRING_H
