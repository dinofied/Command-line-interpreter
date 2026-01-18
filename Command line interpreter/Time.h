#pragma once
#include "Command.h"
#include <ctime>

class Time : public Command {
public:
	Time(string commandName, vector<string> commandArgs, int charCount) : Command(commandName, commandArgs, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();

};

