//
// Created by gouil on 09/07/2023.
//

#include <iostream>
#include "SetCommand.h"
#include "../resp_type/RespSimpleString.h"
#include "../resp_type/RespError.h"
#include "../DataStore.h"

std::unique_ptr<RespType> SetCommand::execute() {
    if (args.size() != 2) {
        return std::make_unique<RespError>("ERR wrong number of arguments for command");
    }

    DataStore &dataStore = DataStore::GetInstance();
    std::cout << "Key: " << args[0] << ", value:" << args[1] << std::endl;
    dataStore.setValue(args[0], args[1]);
    return std::make_unique<RespSimpleString>("OK");
}
