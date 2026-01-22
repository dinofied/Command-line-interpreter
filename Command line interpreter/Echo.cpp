#include "Echo.h"
#include <iostream>
#include <fstream>
using namespace std;


void Echo::runCommand() {

	if (commandArgs.size()) {
		if (Command::isArgText(commandArgs[0])) {
			*outputStream << Command::trimmedText(commandArgs[0]) << endl;
			return;
		}
	}

	//provera da li fajl u koji redirekcija gleda postoji
	/*if (redInfo.inputFile != "") {
		std::ifstream checkExistence(redInfo.inputFile);
		if (!checkExistence) {
			cout << "Fajl ne postoji: " << redInfo.inputFile << endl;
			return;
		}
	}*/

	//ucitava podatke u listu
	string temp;
	vector<string> input;
	while (getline(*inputStream, temp)){
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