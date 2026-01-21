#pragma once
#include "Command.h"
#include <ctime>

class Date : public Command{
public:
	Date(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount) : Command(commandName, commandArgs, redInfo, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();
};

