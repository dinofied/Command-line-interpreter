#pragma once
#include "Command.h"
#include <fstream>
#include "Lexer.h"

class wordCount : public Command {
public:
	wordCount(CommandInfo cmdInfo) : Command(cmdInfo) {

	};

	virtual void runCommand();
};

