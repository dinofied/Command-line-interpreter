#include "Command.h"
#include <iostream>

//checks if the input argument is a file
bool Command::isArgFile(string arg) {
	
	for (char c : arg) {
		if (c == '.' || c == '-' || c == '_') continue;
		if (c < 48 || (c > 57 && c < 65) || (c > 90 && c < 97) || c > 122) return false;
	}
	if (!arg.size()) return false;

	return true;
}

//checks if the input argument is in quotes
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


void Command::switchInputStream(iostream* newInput) {
	inputStream = newInput;
};

void Command::switchOutputStream(iostream* newOutput) {
	outputStream = newOutput;
};

string Command::getName() {
	return commandName;
}

vector<string> Command::getArgs() {
	return commandArgs;
}

string Command::getErrInfo() {
	return errInfo;
}

RedirectionInfo Command::getRedirectionInfo() {
	return redInfo;
};