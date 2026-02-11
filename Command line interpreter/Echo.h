#pragma once
#include "Command.h"

class Echo : public Command { 
public:
	Echo(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};