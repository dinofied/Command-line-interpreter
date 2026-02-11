#pragma once
#include "Command.h"
#include <fstream>

class Touch : public Command{
public:
	Touch(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};


