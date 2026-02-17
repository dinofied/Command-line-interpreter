#include "wordCount.h"


void wordCount::runCommand() {

	//namesta da li ce fajl da se overwrituje ili appenduje
	std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
	if (redInfo.outputFile != "") {

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}

	if (commandArgs.size() == 2) {
		if (Command::isArgText(commandArgs[1])) {
			if (commandArgs[0] == "-c") {
				*outputStream << Command::trimmedText(commandArgs[1]).size();
				if (!redInfo.hasAppend && !redInfo.hasOutput) *outputStream << endl;
				return;
			} 
			else {
				int counter = 0;
				vector<string> broken = Lexer::divideWords(commandArgs[1].substr(1, commandArgs[1].size() - 2));
				counter += broken.size();
				*outputStream << counter;
				if (!redInfo.hasAppend && !redInfo.hasOutput) *outputStream << endl;
				return;
			}
		}
	}
	
	//ucitava podatke u listu
	string temp;
	vector<string> input;
	while (getline(*inputStream, temp)) {
		input.push_back(temp);
	}
	
	int counter = 0;
	for (auto& token : input) {
		if (commandArgs[0] == "-c") {
			counter += token.size();
		}
		else {
			if (token == "" || token == "\n") continue;
			vector<string> broken = Lexer::divideWords(token);
			counter += broken.size();
		}
	}
	
	*outputStream << counter;
	if (!redInfo.hasAppend && !redInfo.hasOutput) *outputStream << endl;
	cin.clear();
};

