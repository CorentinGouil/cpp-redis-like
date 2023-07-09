//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPNULL_H
#define CPP_REDIS_LIKE_RESPNULL_H

#include "RespType.h"

class RespNull : public RespType {
private:

public:
    explicit RespNull() : RespType() {}

    inline std::string buildResponse() override {
        return "$-1\r\n";
    }
};

#endif //CPP_REDIS_LIKE_RESPNULL_H
