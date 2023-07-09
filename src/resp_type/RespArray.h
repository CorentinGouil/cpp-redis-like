//
// Created by gouil on 09/07/2023.
//

#ifndef CPP_REDIS_LIKE_RESPARRAY_H
#define CPP_REDIS_LIKE_RESPARRAY_H


#include <vector>
#include <memory>
#include "RespType.h"

class RespArray : public RespType {
private:
    std::vector<std::shared_ptr<RespType>> value;
public:
    explicit RespArray() : RespType() {}

    std::string buildResponse() override;

    void pushBack(const std::shared_ptr<RespType> &respType);
};


#endif //CPP_REDIS_LIKE_RESPARRAY_H
