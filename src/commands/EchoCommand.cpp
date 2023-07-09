//
// Created by gouil on 09/07/2023.
//

#include <sstream>
#include "EchoCommand.h"

std::string EchoCommand::getResponse() {
    std::stringstream response;

    if (args.size() != 1) {
        response << "-ERR wrong number of arguments for command\r\n";

        return response.str();
    }

    response << "$" << args[0].length() << "\r\n"
             << args[0] << "\r\n";


    return response.str();
}
