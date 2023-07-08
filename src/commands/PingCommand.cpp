//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include "PingCommand.h"

std::string PingCommand::getResponse() {
    if (arg.empty()) return "+PONG\r\n";

    std::stringstream response;

    response << "*";
    response << 1;
    response << "\r\n";

    response << "$";
    response << arg.length();
    response << "\r\n";

    response << arg << "\r\n";

    return response.str();
}
