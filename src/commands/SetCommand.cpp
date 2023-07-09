//
// Created by gouil on 09/07/2023.
//

#include "SetCommand.h"
#include "../resp_type/RespSimpleString.h"

std::unique_ptr<RespType> SetCommand::execute() {
    return std::make_unique<RespSimpleString>("OK");
}
