#include "Echo.h"
#include <iostream>
#include <fstream>
using namespace std;


void Echo::runCommand() {

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


	//provera da li fajl za upis postoji
	std::fstream check(redInfo.inputFile);
	if (!check) {
		cout << "Fajl ne posotji." << endl;
		return;
	}

	if (commandArgs.size()) {
		if (Command::isArgText(commandArgs[0])) {
			*outputStream << Command::trimmedText(commandArgs[0]) << endl;
			return;
		}
	}


	//ucitava podatke u listu
	string temp;
	vector<string> input;
	while (getline(*inputStream, temp)){
		if (temp == "EOF") break;
		input.push_back(temp);
	}


	for (auto &token : input) {
		*outputStream << token << endl;
	}

	cin.clear();
}


void Echo::errReport() {

	cout << "Greska: Nevalidni argumenti za echo komandu." << endl;

};

bool Echo::isValidBody() {
	return true;
};