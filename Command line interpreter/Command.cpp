#include "Command.h"
#include <iostream>

void Command::execute() {

	if (isValidBody()) runCommand();
	else errReport();
};


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


string Command::toString() {
	string cmd = "";
	cmd += commandName;
	for (int i = 0; i < commandArgs.size(); i++) {
		cmd += ' ';
		cmd += commandArgs[i];
	}
	return cmd;
}

bool Command::isLastArgFile() {
	int lastArgSize = commandArgs[commandArgs.size() - 1].size();
	if (lastArgSize < 4) return false;

	string end = commandArgs[commandArgs.size() - 1].substr(lastArgSize - 4, lastArgSize - 1);
	if (end == ".txt") return true;

	return false;
}

string Command::getName() {
	return commandName;
}

vector<string> Command::getArgs() {
	return commandArgs;
}