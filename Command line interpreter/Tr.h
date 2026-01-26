#pragma once
#include "Command.h"

class Tr : public Command{
public:
	Tr(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, charCount, ioInfo) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();

	string editLine(string input, string what, string with);
};

