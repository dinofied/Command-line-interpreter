#include "Head.h"


void Head::runCommand() {
	int lineCount = stoi(commandArgs[0].substr(2, commandArgs[0].size() - 2));
	
	//namesta da li ce fajl da se overwrituje ili appenduje
	std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
	if (redInfo.outputFile != "") {

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}

	//ucitava lineCount podataka u listu
	string temp;
	vector<string> input;
	while (getline(*inputStream, temp)) {
		if (temp == "EOF") break;
		input.push_back(temp);
	}

	int counter = 0;
	for (auto& token : input) {
		if (lineCount > 0) {
			if (counter != 0) *outputStream << endl;
			*outputStream << token << endl;
			lineCount--;
			counter++;
		}
	}

	cin.clear();

};
