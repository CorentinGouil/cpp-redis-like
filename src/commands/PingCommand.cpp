//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include <memory>
#include "PingCommand.h"
#include "../resp_type/RespSimpleString.h"
#include "../resp_type/RespError.h"
#include "../resp_type/RespArray.h"
#include "../resp_type/RespBulkString.h"

std::string PingCommand::getResponse() {
    if (args.empty()) return RespSimpleString("PONG").buildResponse();

    if (args.size() > 1) {
        return RespError(
                "wrong number of arguments (given " + std::to_string(args.size()) + " expected 0..1)"
        ).buildResponse();
    }

    RespArray response;
    response.pushBack(std::make_shared<RespBulkString>(args[0]));
    return response.buildResponse();
}
