#pragma once
#include "Command.h"

class Tr : public Command{
public:
	Tr(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
private:
	string editLine(string input, string what, string with);
};

