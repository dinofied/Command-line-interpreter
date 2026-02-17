#pragma once
#include "Command.h"
#include <ctime>

class Time : public Command {
public:
	Time(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
private:
	string twoDigits(int i);
};

