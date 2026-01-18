#pragma once
#include "Command.h"

class Echo : public Command { 
public:
	Echo(string commandName, vector<string> commandArgs, int charCount) : Command(commandName, commandArgs, charCount) {
	
	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();

	string trimmedBody();
};