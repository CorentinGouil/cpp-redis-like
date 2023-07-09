//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPERROR_H
#define CPP_REDIS_LIKE_RESPERROR_H


#include "RespType.h"

class RespError : public RespType {
private:
    std::string value;
public:
    explicit RespError(std::string value) : RespType(), value(std::move(value)) {}

    inline std::string buildResponse() override {
        return "-" + value + "\r\n";
    }

};


#endif //CPP_REDIS_LIKE_RESPERROR_H
