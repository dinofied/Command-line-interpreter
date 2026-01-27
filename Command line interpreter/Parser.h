#pragma once
#include <string>
#include <vector>
#include "Command.h"

class Parser {
public:

	static ParsedCommand parsedCommand(const std::vector<std::string>& tokens);

private:

	Parser() {};
};

