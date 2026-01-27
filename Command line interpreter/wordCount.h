#pragma once
#include "Command.h"
#include <fstream>

class wordCount : public Command {
public:
	wordCount(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();
};

