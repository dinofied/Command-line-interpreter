#include "Truncate.h"


void Truncate::runCommand() {

	std::ofstream file(commandArgs[0]);

};

bool Truncate::isValidBody() {
	if (commandArgs.size() != 1) return false;
	if (Command::isLastArgFile()) return true;
	return false;
};

void Truncate::errReport() {

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
