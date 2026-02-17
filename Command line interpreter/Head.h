#pragma once
#include "Command.h"
#include <fstream>

class Head : public Command{
public:
	Head(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();

};

