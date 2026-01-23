#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "cmdFactory.h"
#include "Echo.h"
#include "readySign.h"
#include "Lexer.h"
#include "Collector.h"
#include "Parser.h"
#include "StreamManager.h"
using namespace std;

class CommandLineInterpreter {
public:
	static CommandLineInterpreter& terminalInstance() {
		static CommandLineInterpreter instance;
		return instance;
	}

	void run(std::istream& input, std::ostream& output, bool inBatch);

	string getReadySign();
	void setReadySign(string input);


private:
	string readySign;
	bool isBatch = false;


	CommandLineInterpreter() : readySign("&") {};

};

