//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include "UnknownCommand.h"
#include "../resp_type/RespError.h"

std::string UnknownCommand::getResponse() {
    return RespError("unknown command '" + args[0]).buildResponse();
}
