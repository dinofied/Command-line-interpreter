#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "cmdFactory.h"
#include "Echo.h"
#include "readySign.h"
#include "Lexer.h"
using namespace std;

class CommandLineInterpreter {
public:
	static CommandLineInterpreter& terminalInstance() {
		static CommandLineInterpreter instance;
		return instance;
	}

	void run();

	string getReadySign();
	void setReadySign(string input);

private:
	string readySign;


	CommandLineInterpreter() : readySign("&") {};

};

