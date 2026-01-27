#pragma once
#include "Command.h"
#include "CommandLineInterpreter.h"

class Batch : public Command{
public:
	Batch(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();
};

