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
	return true;

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