#pragma once
#include "Command.h"
#include <ctime>

class Date : public Command{
public:
	Date(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();

private:

	string twoDigits(int i);
};

