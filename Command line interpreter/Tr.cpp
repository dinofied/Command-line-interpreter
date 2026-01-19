#include "Tr.h"


void Tr::runCommand() {

	if (commandArgs.size() == 1) std::cout << "Komanda jos ne podrzava unos konzole." << std::endl;
	else if (commandArgs.size() == 2) {

	}
	else {

	}

};

bool Tr::isValidBody() {
	if (commandArgs.size() < 1 || commandArgs.size() > 3) return false;


	//swapping args so my fucnctions work since they check the last arg
	string swap = commandArgs[0];
	if (commandArgs.size() == 2) {
		commandArgs[0] = commandArgs[1];
		commandArgs[1] = swap;
		if (!isLastArgFile()) return false;
	}
	else if (commandArgs.size() == 3) {
		commandArgs[0] = commandArgs[1];
		commandArgs[1] = swap;
		commandArgs[1] = commandArgs[2];
		commandArgs[2] = swap;
		if (!isLastArgFile()) return false;
		if (commandArgs[1][0] != '"' || commandArgs[1][commandArgs[1].size() - 1] != '"') return false;
	}
	if (commandArgs[0][0] != '-') return false;

	return true;
};

void Tr::errReport() {
	if (commandArgs.size() > 3) {
		std::cout << "Uneto previse argumenata." << endl;
	}
	else if (commandArgs.size() < 1) {
		std::cout << "Uneto premalo argumenata." << endl;
	}
	else std::cout << "Greska pri unosu argumenata komande:" << endl;

	std::cout << Command::toString() << std::endl;
	Command::errPlacesReport();
};

