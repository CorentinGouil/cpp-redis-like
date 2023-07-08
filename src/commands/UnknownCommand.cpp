//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include "UnknownCommand.h"

std::string UnknownCommand::getResponse() {
    std::stringstream response;

    response << "-unknown command '" << arg << "'\r\n";

    return response.str();
}
