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
	size_t pipeId;
	size_t pipeCount;
};

struct IOStreamInfo {
	std::istream* input;
	std::ostream* output;
};
