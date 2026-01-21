#pragma once
#include "Command.h"
#include "CommandLineInterpreter.h"

class Batch : public Command{
public:
	Batch(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, charCount, ioInfo) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();
};

