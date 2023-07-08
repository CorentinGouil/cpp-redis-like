//
// Created by gouil on 08/07/2023.
//

#include "PingCommand.h"

std::string PingCommand::getResponse() {
    return "+PONG\r\n";
}
