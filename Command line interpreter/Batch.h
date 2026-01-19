#pragma once
#include "Command.h"
#include "CommandLineInterpreter.h"

class Batch : public Command{
public:
	Batch(string commandName, vector<string> commandArgs, int charCount) : Command(commandName, commandArgs, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();
};

