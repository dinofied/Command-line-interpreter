#pragma once
#include "Command.h"
#include "CommandLineInterpreter.h"

class Prompt : public Command {
public:
	Prompt(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();
};

