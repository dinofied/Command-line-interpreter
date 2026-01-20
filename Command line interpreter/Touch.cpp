#include "Touch.h"


void Touch::runCommand() {
	std::ifstream test(commandArgs[0]);
	if (test) {
		std::cout << "Fajl vec postoji:" << endl;
		std::cout << toString() << endl;
		return;
	}

	std::ofstream newFile(commandArgs[0]);

};

bool Touch::isValidBody() {
	if (commandArgs.size() != 1) return false;
	if (Command::isArgFile(commandArgs[0])) return true;
	return false;

};

void Touch::errReport() {

	if (commandArgs.size() > 1) {
		std::cout << "Uneto previse argumenata." << endl;
	}
	else if (commandArgs.size() < 1) {
		std::cout << "Uneto premalo argumenata." << endl;
	}
	else std::cout << "Greska pri unosu argumenata komande:" << endl;

	std::cout << Command::toString() << std::endl;
	Command::errPlacesReport();

};