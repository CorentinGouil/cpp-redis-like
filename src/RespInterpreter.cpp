//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include <iostream>
#include <vector>
#include "RespInterpreter.h"
#include "commands/PingCommand.h"

std::unique_ptr<Command> RespInterpreter::getCommandHandler() {
    std::cout << command << std::endl;
    std::stringstream commandStream(command);

    std::vector<std::string> splitCommand;

    std::string line;
    int i = 0;
    while (std::getline(commandStream, line)) {
        splitCommand.push_back(line);
    }

    // Array
    if (splitCommand[0][0] == '*') {
        int length = std::stoi(&splitCommand[0][1]);

        if (splitCommand[2] == "ping\r") {
            if (length == 1) {
                return std::make_unique<PingCommand>();
            }
            int argLength = std::stoi(&splitCommand[3][1]);
            return std::make_unique<PingCommand>(splitCommand[4].substr(0, argLength));
        }
    }


    return std::make_unique<PingCommand>();
}
