#pragma once
#include <vector>
#include <string>


struct RedirectionInfo {
	std::string inputFile = "";
	std::string outputFile = "";
	bool hasInput = false;
	bool hasOutput = false;
	bool hasAppend = false;
};

struct ParsedCommand {
	std::vector<std::string> body;
	RedirectionInfo redirection;
};

struct PipeInfo {
	int pipeId;
	int pipeCount;
};