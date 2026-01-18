#pragma once
#include <string>
#include <vector>
#include "Echo.h"
#include "Time.h"

using namespace std;
class commandFactory {
public:

	static Command* createCmd(vector<string> words, int charCount);

private:
	string commandName;
	vector<string> commandArgs;

	static void nameDoesntExsist(string commandName, vector<string> commandArgs);

	commandFactory() {};

};

