#include "wordCount.h"


void wordCount::runCommand() {
	int counter = 0;
	if (isLastArgFile()) {

		std::ifstream file(commandArgs[commandArgs.size() - 1]);
		if (!file) {
			cout << "Fajl nije pronadjen:" << endl;
			cout << toString() << endl;

			return;
		}
		string temp;

		while (std::getline(file, temp)) {
			if (temp == "") continue;
			if (commandArgs[0] == "-c") counter += temp.size();
			else {
				for (char c : temp) {
					if (isspace(c)) counter++;
				}
				counter++;
			}
		}
		std::cout << counter << endl;
		file.clear();
		file.seekg(0, std::ios::beg);
	}
	else {
		if (commandArgs[0] == "-c") {
			counter += trimmedBody().size();
		}
		else {
			for (char c : trimmedBody()) {
				if (isspace(c)) counter++;
			}
			counter++;
		}
		std::cout << counter << endl;
	}


};

bool wordCount::isValidBody() {
	if (commandArgs.size() != 2) return false;
	if (commandArgs[0] != "-w" && commandArgs[0] != "-c") return false;
	if (Command::isLastArgFile()) return true;
	if (Command::isLastArgText()) return true;
	return false;
};

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

string trimmedBody();