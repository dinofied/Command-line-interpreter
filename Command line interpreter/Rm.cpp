#include "Rm.h"


void Rm::runCommand() {

	if (std::remove(commandArgs[0].c_str()) != 0){
		std::cout << "Fajl \"" << commandArgs[0] << "\" ne postoji." << std::endl;
	};

};

bool Rm::isValidBody() {

	return true;

};

void Rm::errReport() {

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