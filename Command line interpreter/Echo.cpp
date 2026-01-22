#include "Echo.h"
#include <iostream>
#include <fstream>
using namespace std;


void Echo::runCommand() {

	string temp;
	vector<string> input;
	if (commandArgs.size()) {
		if (Command::isArgText(commandArgs[0])) {
			*outputStream << Command::trimmedText(commandArgs[0]) << endl;
			return;
		}
	}


	if (redInfo.inputFile != "") {
		std::ifstream checkExistence(redInfo.inputFile);
		if (!checkExistence) {
			cout << "Fajl ne postoji: " << redInfo.inputFile << endl;
			return;
		}
	}
	if (redInfo.outputFile != "") {
		std::ifstream checkExistence(redInfo.outputFile);
		if (!checkExistence) {
			cout << "Fajl ne postoji: " << redInfo.outputFile << endl;
			return;
		}

		std::ofstream file(redInfo.outputFile);
	}

	while (getline(*inputStream, temp)){
		if (temp == "EOF") break;
		input.push_back(temp);
	}

	for (auto &token : input) {
		*outputStream << token << endl;
	}
}


void Echo::errReport() {

	cout << "Greska: Nevalidni argumenti za echo komandu." << endl;

};

bool Echo::isValidBody() {
	return true;
};