#include "Head.h"


void Head::runCommand() {
	int lineCount = stoi(commandArgs[0].substr(2, commandArgs[0].size() - 2));
	
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

	//ucitava lineCount podataka u listu
	string temp;
	vector<string> input;
	while (getline(*inputStream, temp)) {
		if (temp == "EOF") break;
		input.push_back(temp);
	}

	for (auto& token : input) {
		if (lineCount > 0) {
			*outputStream << token << endl;
			lineCount--;
		}
	}

	cin.clear();

};
