#pragma once
#include "Command.h"
#include <cstdio>
#include <fstream>

class Rm : public Command {
public:
	Rm(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, charCount, ioInfo) {

	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();


};

