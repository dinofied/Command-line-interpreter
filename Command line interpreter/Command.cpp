#include "Command.h"
#include <iostream>

void Command::execute() {

	if (isValidBody()) {

		runCommand();
	}
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
bool Command::isArgFile(string arg) {
	size_t argSize = arg.size() - 1;
	if (argSize < 4) return false;

	string end = arg.substr(argSize - 3, argSize);
	if (end == ".txt") return true;

	return false;
}

//checks if the last argument is a textual arg
bool Command::isArgText(string arg) {
	int l = -1, r = -1;

	for (int i = 0; i < arg.size(); i++) {
		if (arg[i] == '"' && l != -1 && r == -1) r = i;
		if (arg[i] == '"' && l == -1) l = i;
	}

	for (int i = 0; i < arg.size(); i++) {
		if (i < l || i > r) return false;
	}

	return true;
}

//returns the arg without quotation marks
string Command::trimmedText(string arg) {
	return arg.substr(1, arg.size() - 2);
}

string Command::getName() {
	return commandName;
}

vector<string> Command::getArgs() {
	return commandArgs;
}

RedirectionInfo Command::getRedirectionInfo() {
	return redInfo;
};