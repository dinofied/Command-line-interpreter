#include "Head.h"


void Head::runCommand() {
	int lineCount = stoi(commandArgs[0].substr(1, commandArgs[0].size() - 1));
	
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
	while (getline(*inputStream, temp) && lineCount > 0) {
		if (temp == "EOF") break;
		input.push_back(temp);
		lineCount--;
	}

	for (auto& token : input) {
		*outputStream << token << endl;
	}

	cin.clear();

};

bool Head::isValidBody() {

	return true;
};

void Head::errReport() {

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