//
// Created by gouil on 09/07/2023.
//

#include <sstream>
#include "EchoCommand.h"
#include "../resp_type/RespError.h"
#include "../resp_type/RespBulkString.h"

std::string EchoCommand::getResponse() {
    if (args.size() != 1) {
        return RespError("ERR wrong number of arguments for command").buildResponse();
    }

    return RespBulkString(args[0]).buildResponse();
}
