#pragma once
#include "Command.h"

class Time : public Command {
public:
	Time(string commandName, vector<string> commandArgs) : Command(commandName, commandArgs) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();

};

