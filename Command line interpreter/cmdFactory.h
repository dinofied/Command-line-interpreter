#pragma once
#include <string>
#include <vector>
#include "Echo.h"
#include "Time.h"
#include "Date.h"
#include "Touch.h"
#include "wordCount.h"
#include "Prompt.h"

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

