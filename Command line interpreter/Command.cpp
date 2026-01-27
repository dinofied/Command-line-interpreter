#include "Command.h"
#include <iostream>

//checks if the input argument is a file
bool Command::isArgFile(string arg) {
	int argSize = arg.size() - 1;
	if (argSize < 4) return false;

	string end = arg.substr(argSize - 3, argSize);
	if (end == ".txt") return true;

	return false;
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

RedirectionInfo Command::getRedirectionInfo() {
	return redInfo;
};