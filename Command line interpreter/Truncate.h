#pragma once
#include "Command.h"
#include <fstream>

class Truncate : public Command{
public:
	Truncate(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();
};

