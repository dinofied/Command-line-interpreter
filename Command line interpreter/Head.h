#pragma once
#include "Command.h"
#include <fstream>

class Head : public Command{
public:
	Head(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();

};

