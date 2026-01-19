#pragma once
#include "Command.h"

class Tr : public Command{
public:
	Tr(string commandName, vector<string> commandArgs, int charCount) : Command(commandName, commandArgs, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();


};

