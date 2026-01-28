#include "wordCount.h"


void wordCount::runCommand() {
	
	if (commandArgs.size() == 2) {
		if (Command::isArgText(commandArgs[1])) {
			if (commandArgs[0] == "-c") {
				*outputStream << Command::trimmedText(commandArgs[1]).size() << endl;
				return;
			} 
			else {
				int counter = 0;
				for (int i = 0; i < commandArgs[1].size(); i++) {
					if (commandArgs[1][i] == ' ') counter++;
				}
				if (commandArgs[1] != "") counter++;
				*outputStream << counter << endl;
				return;
			}
		}
	}
	
	//ucitava podatke u listu
	string temp;
	vector<string> input;
	while (getline(*inputStream, temp)) {
		if (temp == "EOF") break;
		input.push_back(temp);
	}

	//namesta da li ce fajl da se overwrituje ili appenduje
	std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
	if (redInfo.outputFile != "") {

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}
	
	int counter = 0;
	for (auto& token : input) {
		if (token == "EOF") continue;
		if (commandArgs[0] == "-c") {
			counter += token.size();
		}
		else {
			if (token == "" || token == "\n") continue;
			for (char c : token) {
				if (c == ' ') counter++;
			}
			if (token != "") counter++;
		}
	}
	
	*outputStream << counter;
	cin.clear();
};

