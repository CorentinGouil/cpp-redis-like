//
// Created by gouil on 09/07/2023.
//

#include <sstream>
#include "RespArray.h"

std::string RespArray::buildResponse() {
    std::stringstream response;
    response << "*" << value.size() << "\r\n";

    for (const auto &v: value) {
        response << v->buildResponse();
    }

    return response.str();
}

void RespArray::pushBack(const std::shared_ptr<RespType> &respType) {
    value.push_back(respType);
}
