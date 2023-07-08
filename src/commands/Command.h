//
// Created by gouil on 08/07/2023.
//

#ifndef CPP_REDIS_LIKE_COMMAND_H
#define CPP_REDIS_LIKE_COMMAND_H


#include <string>

class Command {
public:
    virtual std::string getResponse() = 0;

    virtual ~Command() = default;
};


#endif //CPP_REDIS_LIKE_COMMAND_H
