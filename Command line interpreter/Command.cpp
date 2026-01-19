#include "Command.h"
#include <iostream>

void Command::execute() {

	if (isValidBody()) runCommand();
	else errReport();
};

//used for pointing out the report location when reporting the error
void Command::errPlacesReport() {
	if (!errPlaces.size()) return;
	int errPlace = 0;
	int err = errPlaces[errPlace];

	for (int i = 0; i < charCount; i++) {
		if (i == err) {
			std::cout << '^';
			errPlace++;
			if (errPlace < errPlaces.size()) {
				err = errPlaces[errPlace];
			}
		}
		else std::cout << " ";
	} 
	std::cout << std::endl;

};

//returns the command with args in string format
string Command::toString() {
	string cmd = "";
	cmd += commandName;
	for (int i = 0; i < commandArgs.size(); i++) {
		cmd += ' ';
		cmd += commandArgs[i];
	}
	return cmd;
}

//checks if the last argument is a file
bool Command::isLastArgFile() {
	int lastArgSize = commandArgs[commandArgs.size() - 1].size();
	if (lastArgSize < 4) return false;

	string end = commandArgs[commandArgs.size() - 1].substr(lastArgSize - 4, lastArgSize - 1);
	if (end == ".txt") return true;

	return false;
}

//checks if the last argument is a textual arg
bool Command::isLastArgText() {
	int l = -1, r = -1;
	int lastArgId = commandArgs.size() - 1;

	for (int i = 0; i < commandArgs[lastArgId].size(); i++) {
		if (commandArgs[lastArgId][i] == '"' && l != -1 && r == -1) r = i;
		if (commandArgs[lastArgId][i] == '"' && l == -1) l = i;
	}

	for (int i = 0; i < commandArgs[lastArgId].size(); i++) {
		if (i < l || i > r) errPlaces.push_back(i + 1 + commandName.size());
	}

	if (errPlaces.empty()) {
		return true;
	}
}

//returns the arg without quotation marks
string Command::trimmedBody() {
	string trimmed = "";
	int it = 0;
	int argId = commandArgs.size() - 1;
	while (commandArgs[argId][it] != '"') it++;
	
	for (int i = it + 1; (i < commandArgs[argId].size() && commandArgs[argId][i] != '"'); i++) trimmed += commandArgs[argId][i];
	return trimmed;
}

string Command::getName() {
	return commandName;
}

vector<string> Command::getArgs() {
	return commandArgs;
}