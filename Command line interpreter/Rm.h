#pragma once
#include "Command.h"
#include <cstdio>
#include <fstream>

class Rm : public Command {
public:
	Rm(string commandName, vector<string> commandArgs, int charCount) : Command(commandName, commandArgs, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();


};

