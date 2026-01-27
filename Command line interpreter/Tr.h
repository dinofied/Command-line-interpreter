#pragma once
#include "Command.h"

class Tr : public Command{
public:
	Tr(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();
private:
	string editLine(string input, string what, string with);
};

