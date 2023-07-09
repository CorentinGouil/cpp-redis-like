//
// Created by gouil on 09/07/2023.
//

#include <iostream>
#include "GetCommand.h"
#include "../resp_type/RespSimpleString.h"
#include "../resp_type/RespError.h"
#include "../DataStore.h"
#include "../resp_type/RespBulkString.h"
#include "../resp_type/RespNull.h"

std::unique_ptr<RespType> GetCommand::execute() {
    if (args.size() != 1) {
        return std::make_unique<RespError>("ERR wrong number of arguments for command");
    }

    std::cout << "Get Command with Key: " << args[0] << std::endl;
    DataStore &dataStore = DataStore::GetInstance();
    std::string value = dataStore.getValue(args[0]);

    if (value.empty()) {
        return std::make_unique<RespNull>();
    }

    return std::make_unique<RespBulkString>(value);
}
