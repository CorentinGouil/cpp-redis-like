//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPTYPE_H
#define CPP_REDIS_LIKE_RESPTYPE_H


#include <string>

class RespType {

public:
    virtual std::string buildResponse() = 0;

    virtual ~RespType() = default;

};


#endif //CPP_REDIS_LIKE_RESPTYPE_H
