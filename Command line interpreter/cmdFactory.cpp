#include "cmdFactory.h"


Command* commandFactory::createCmd(vector<string> words) {
	if (!words.size()) {
		cout << "Nevalidan unos." << endl;
		return nullptr;
	}
	commandName = words[0];
	commandArgs = commandArgs = std::vector<std::string>(words.begin() + 1, words.end());



	
	if (commandName == "echo") {
		Echo* newCmd = new Echo(commandName, commandArgs);
		return newCmd;
	}
	if (commandName == "time") {
		Time* newCmd = new Time(commandName, commandArgs);
		return newCmd;
	}


	nameDoesntExsist();
	return nullptr;
};


void commandFactory::nameDoesntExsist() {

	cout << "Komanda ne postoji: " << endl;
	cout << commandName << " ";
	for (int i = 0; i < commandArgs.size(); i++) {
		cout << commandArgs[i];
		if (i != commandArgs.size() - 1) cout << " ";
	}
	cout << endl;
	for (int i = 0; i < commandName.size() / 2; i++) {
		cout << " ";
	}
	cout << "^" << endl;

};

