//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include "PingCommand.h"

std::string PingCommand::getResponse() {
    if (args.empty()) return "+PONG\r\n";

    std::stringstream response;

    if (args.size() > 1) {
        response << "-" << "wrong number of arguments (given "
                 << args.size() << " expected 0..1)\r\n";
        
        return response.str();
    }

    response << "*" << 1 << "\r\n"
             << "$" << args[0].length() << "\r\n"
             << args[0] << "\r\n";

    return response.str();
}
