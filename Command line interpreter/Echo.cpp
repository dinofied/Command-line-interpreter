#include "Echo.h"
#include <iostream>
#include <fstream>
using namespace std;


void Echo::runCommand() {

	//namesta da li ce fajl da se overwrituje ili appenduje
	std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
	if (redInfo.outputFile != "") {

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}

	//slucaj gde je argument text 
	if (commandArgs.size()) {
		if (Command::isArgText(commandArgs[0])) {
			*outputStream << Command::trimmedText(commandArgs[0]);
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

	int counter = 0;
	for (auto &token : input) {
		if (counter != 0) *outputStream << endl;
		*outputStream << token;
		counter++;
	}

	cin.clear();
}
