#include "Echo.h"
#include <iostream>
#include <fstream>
using namespace std;


void Echo::runCommand() {

	if (isArgFile(commandArgs[0])) {
		std::ifstream file(commandArgs[commandArgs.size() - 1]);
		if (!file) {
			cout << "Fajl nije pronadjen:" << endl;
			cout << toString() << endl;

			return;
		}
		string temp;

		while (std::getline(file, temp)) {
			cout << temp << endl;
		}

		file.clear();
		file.seekg(0, std::ios::beg);
		
	}
	else std::cout << Command::trimmedText(commandArgs[0]) << std::endl;

}


void Echo::errReport() {

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

bool Echo::isValidBody() {
	if (commandArgs.size() != 1) return false;
	if (Command::isArgFile(commandArgs[0])) return true;
	if (Command::isArgText(commandArgs[0])) return true;
	return false;
};