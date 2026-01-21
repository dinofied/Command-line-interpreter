#pragma once
#include "Command.h"
#include <fstream>

class Head : public Command{
public:
	Head(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount) : Command(commandName, commandArgs, redInfo, charCount) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();

};

