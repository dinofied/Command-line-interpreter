#include "cmdFactory.h"


Command* commandFactory::createCmd(vector<string> words, int charCount) {
	if (words.size() == 0) {
		cout << "Nevalidan unos." << endl;
		return nullptr;
	}
	string commandName = words[0];
	vector<string> commandArgs = std::vector<std::string>(words.begin() + 1, words.end());

	
	if (commandName == "echo") {
		return (Echo*) new Echo(commandName, commandArgs, charCount);
	}
	if (commandName == "time") {
		return (Time*) new Time(commandName, commandArgs, charCount);
	}
	if (commandName == "date") {
		return (Date*) new Date(commandName, commandArgs, charCount);
	}
	if (commandName == "wc") {
		return (wordCount*) new wordCount(commandName, commandArgs, charCount);
	}
	if (commandName == "touch") {
		return (Touch*) new Touch(commandName, commandArgs, charCount);
	}
	if (commandName == "prompt") {
		return (Prompt*) new Prompt(commandName, commandArgs, charCount);
	}
	if (commandName == "batch") {
		return (Batch*) new Batch(commandName, commandArgs, charCount);
	}

	

	nameDoesntExsist(commandName, commandArgs);
	return nullptr;
};


void commandFactory::nameDoesntExsist(string commandName, vector<string> commandArgs) {

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

