#pragma once
#include "Command.h"
#include <cstdio>
#include <fstream>

class Rm : public Command {
public:
	Rm(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};

