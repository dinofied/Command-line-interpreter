#pragma once
#include <string>
#include <vector>
#include "Echo.h"
#include "Time.h"

using namespace std;
class commandFactory {
public:
	static commandFactory& factoryInstance() {
		static commandFactory instance;
		return instance;
	};
	
	Command* createCmd(vector<string> words);

private:
	string commandName;
	vector<string> commandArgs;

	void nameDoesntExsist();

	commandFactory() {};

};

