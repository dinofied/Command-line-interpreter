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
		std::ifstream checkExistence(redInfo.outputFile);
		if (!checkExistence) {
			cout << "Fajl ne postoji: " << redInfo.outputFile << endl;
			return;
		}

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}
	int counter = 0;
	for (auto& token : input) {
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
	
	*outputStream << counter << endl;

};

//checks the validity of command arguments
bool wordCount::isValidBody() {
	return true;
};


//reports the type of error
void wordCount::errReport() {

	if (commandArgs.size() > 2) {
		std::cout << "Uneto previse argumenata." << endl;
	}
	else if (commandArgs.size() < 1) {
		std::cout << "Uneto premalo argumenata." << endl;
	}
	else std::cout << "Greska pri unosu argumenata komande:" << endl;

	std::cout << Command::toString() << std::endl;
	Command::errPlacesReport();

};

bool wordCount::determineMode() {
	if (commandArgs[0] == "-w") return false;
	return true;
};
