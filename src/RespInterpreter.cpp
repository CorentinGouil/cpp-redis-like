//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include <iostream>
#include <vector>
#include "RespInterpreter.h"
#include "commands/PingCommand.h"

std::unique_ptr<Command> RespInterpreter::getCommandHandler() {
    std::stringstream commandStream(command);

    std::vector<std::string> splitCommand;

    std::string line;
    int i = 0;
    while (std::getline(commandStream, line)) {
        splitCommand.push_back(line);
    }
    
    if (splitCommand[2] == "ping\r") {
        std::cout << "ping!" << std::endl;
        return std::make_unique<PingCommand>();
    }

    return std::make_unique<PingCommand>();
}
