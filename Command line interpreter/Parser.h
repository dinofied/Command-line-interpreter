#pragma once
#include <string>
#include <vector>
#include "Command.h"

class Parser {
public:

	static Parser& parserInstance() {
		static Parser instance;
		return instance;
	}

	ParsedCommand parsedCommand(const std::vector<std::string>& tokens);


private:

	Parser() {};
};

