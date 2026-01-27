#pragma once
#include "Command.h"
#include <fstream>

class Touch : public Command{
public:
	Touch(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();
};


