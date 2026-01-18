#pragma once
#include "Command.h"

class Echo : public Command { 
public:
	Echo(string commandName, vector<string> commandArgs) : Command(commandName, commandArgs) {
	
	};

private:

	virtual void runCommand();

	virtual bool isValidBody();

	virtual void errReport();

	void trimBody(int l, int r);
};