#pragma once
#include "Command.h"

class Error : public Command {
public:
	Error(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};