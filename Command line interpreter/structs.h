#pragma once
#include <vector>
#include <string>

//used for storing redirection specific data
struct RedirectionInfo {
	std::string inputFile = "";
	std::string outputFile = "";
	bool hasInput = false;
	bool hasOutput = false;
	bool hasAppend = false;
};

//used after the parser determines what is the body of the cmd and what are its redirections
struct ParsedCommand {
	std::vector<std::string> body;
	RedirectionInfo redirection;
};

//info on the pipe the command is in
struct PipeInfo {
	size_t pipeId;
	size_t pipeCount;
};

//io info
struct IOStreamInfo {
	std::istream* input;
	std::ostream* output;
};

//created after the command is fully proccessed and is ready to either execute or error report
struct CommandInfo {
	std::vector<std::string> body;
	RedirectionInfo redirection;
	IOStreamInfo ioInfo;
	std::string errInfo;
};
