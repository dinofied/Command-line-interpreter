#pragma once
#include "Command.h"
#include <cstdio>
#include <fstream>

class Rm : public Command {
public:
	Rm(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();
};

