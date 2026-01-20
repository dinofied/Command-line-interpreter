#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "cmdFactory.h"
#include "Echo.h"
#include "readySign.h"
#include "Lexer.h"
#include "Collector.h"
using namespace std;

class CommandLineInterpreter {
public:
	static CommandLineInterpreter& terminalInstance() {
		static CommandLineInterpreter instance;
		return instance;
	}

	void run(std::istream& stream);

	string getReadySign();
	void setReadySign(string input);

	void isBatchSwitch();

private:
	string readySign;
	bool isBatch = false;


	CommandLineInterpreter() : readySign("&") {};

};

