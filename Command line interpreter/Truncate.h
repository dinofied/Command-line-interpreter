#pragma once
#include "Command.h"
#include <fstream>

class Truncate : public Command{
public:
	Truncate(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};

