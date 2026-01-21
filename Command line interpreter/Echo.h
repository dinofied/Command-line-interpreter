#pragma once
#include "Command.h"

class Echo : public Command { 
public:
	Echo(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount) : Command(commandName, commandArgs, redInfo, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();
};