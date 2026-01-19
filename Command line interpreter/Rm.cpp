#include "Rm.h"


void Rm::runCommand() {

	if (std::remove(commandArgs[0].c_str()) != 0){
		std::cout << "Fajl nije obrisan ili nije ni postojao." << std::endl;
	};

};

bool Rm::isValidBody() {

	if (commandArgs.size() != 1) return false;
	if (Command::isLastArgFile()) return true;
	return false;

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