//
// Created by gouil on 08/07/2023.
//

#include <sstream>
#include <iostream>
#include <vector>
#include "RespInterpreter.h"
#include "commands/PingCommand.h"
#include "commands/UnknownCommand.h"

RespInterpreter::RespCommand RespInterpreter::getRespCommand() {
    RespInterpreter::RespCommand res;

    std::stringstream commandStream(command);

    std::vector<std::string> splitCommand;

    std::string line;
    while (std::getline(commandStream, line)) {
        splitCommand.push_back(line);
    }

    // Array
    if (splitCommand[0][0] == '*') {
        const int length = std::stoi(&splitCommand[0][1]);

        const int commandLength = std::stoi(&splitCommand[1][1]);
        res.command = splitCommand[2].substr(0, commandLength);
        for (auto &c: res.command) c = toupper(c);

        // Bind args
        for (int i = 1; i < length; i++) {
            const int argLengthIndex = i * 2 + 1;
            const int argValueIndex = argLengthIndex + 1;

            const int elemLength = std::stoi(&splitCommand[argLengthIndex][1]);
            const std::string elemValue = splitCommand[argValueIndex].substr(0, elemLength);
            res.args.push_back(elemValue);
        }
    }

    return res;
}

std::unique_ptr<Command> RespInterpreter::getCommandHandler() {
    RespCommand respCommand = getRespCommand();

    if (respCommand.command == "PING") {
        return std::make_unique<PingCommand>(respCommand.args);
    }

    return std::make_unique<UnknownCommand>(respCommand.args);
}


