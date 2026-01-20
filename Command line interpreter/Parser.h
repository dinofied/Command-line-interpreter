#pragma once
#include <string>
#include <vector>
#include "Command.h"

struct RedirectionInfo {
	std::string inputFile;
	std::string outputFile;
	bool hasInput = false;
	bool hasOutput = false;
	bool hasAppend = false;
};

struct ParsedCommand {
	std::vector<std::string> tokens;
	RedirectionInfo redirection;
};

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

