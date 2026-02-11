#pragma once
#include "Command.h"
#include "CommandLineInterpreter.h"

class Batch : public Command{
public:
	Batch(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};

