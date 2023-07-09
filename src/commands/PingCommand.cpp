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

std::unique_ptr<RespType> PingCommand::execute() {
    if (args.empty()) return std::make_unique<RespSimpleString>("PONG");

    if (args.size() > 1) {
        return std::make_unique<RespError>(
                "wrong number of arguments (given " + std::to_string(args.size()) + " expected 0..1)"
        );
    }

    RespArray response;
    response.pushBack(std::make_shared<RespBulkString>(args[0]));
    return std::make_unique<RespArray>(response);
}
