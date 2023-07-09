//
// Created by gouil on 09/07/2023.
//

#include <sstream>
#include "EchoCommand.h"
#include "../resp_type/RespError.h"
#include "../resp_type/RespBulkString.h"

std::unique_ptr<RespType> EchoCommand::execute() {
    if (args.size() != 1) {
        return std::make_unique<RespError>("ERR wrong number of arguments for command");
    }

    return std::make_unique<RespBulkString>(args[0]);
}
