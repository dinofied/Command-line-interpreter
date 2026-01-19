#pragma once
#include "Command.h"
#include <fstream>

class Head : public Command{
public:
	Head(string commandName, vector<string> commandArgs, int charCount) : Command(commandName, commandArgs, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();

};

