#pragma once
#include "Command.h"
#include <ctime>

class Date : public Command{
public:
	Date(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) : Command(commandName, commandArgs, redInfo, ioInfo) {

	};

	virtual void runCommand();

private:

	string twoDigits(int i);
};

