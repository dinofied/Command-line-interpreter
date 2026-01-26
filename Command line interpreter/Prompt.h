#pragma once
#include "Command.h"
#include "CommandLineInterpreter.h"

class Prompt : public Command {

public:

	Prompt(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, charCount, ioInfo) {

	};

private:
	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();
};

