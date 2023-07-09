//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include "UnknownCommand.h"
#include "../resp_type/RespError.h"

std::unique_ptr<RespType> UnknownCommand::execute() {
    return std::make_unique<RespError>("unknown command '" + args[0]);
}
