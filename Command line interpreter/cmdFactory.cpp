#include "cmdFactory.h"



Command* commandFactory::createCmd(ParsedCommand parsedCommand , int charCount) {
	if (!parsedCommand.body.size()) {
		cout << "Nevalidan unos." << endl;
		return nullptr;
	}
	string commandName = parsedCommand.body[0];
	vector<string> commandArgs = std::vector<std::string>(parsedCommand.body.begin() + 1, parsedCommand.body.end());
	RedirectionInfo redInfo = parsedCommand.redirection;

	
	if (commandName == "echo") {
		return (Echo*) new Echo(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "time") {
		return (Time*) new Time(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "date") {
		return (Date*) new Date(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "wc") {
		return (wordCount*) new wordCount(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "touch") {
		return (Touch*) new Touch(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "prompt") {
		return (Prompt*) new Prompt(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "batch") {
		return (Batch*) new Batch(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "truncate") {
		return (Truncate*) new Truncate(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "rm") {
		return (Rm*) new Rm(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "head") {
		return (Head*) new Head(commandName, commandArgs, redInfo, charCount);
	}
	if (commandName == "tr") {
		return (Tr*) new Tr(commandName, commandArgs, redInfo, charCount);
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

