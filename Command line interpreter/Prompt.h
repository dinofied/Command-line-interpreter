#pragma once
#include "Command.h"
#include "CommandLineInterpreter.h"

class Prompt : public Command {
public:
	Prompt(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};

