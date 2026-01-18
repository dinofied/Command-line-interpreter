#include "Echo.h"
#include <iostream>
#include <fstream>
using namespace std;


void Echo::runCommand() {

	if (isLastArgFile()) {
		std::ifstream file(commandArgs[0]);
		if (!file) {
			cout << "Fajl nije pronadjen:" << endl;
			cout << toString() << endl;

			return;
		}
		string temp;

		while (std::getline(file, temp)) {
			cout << temp << endl;
		}
		
	}
	else std::cout << trimmedBody() << std::endl;

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
	if (isLastArgFile()) return true;

	int l = -1, r = -1;

	for (int i = 0; i < commandArgs[0].size(); i++) {
		if (commandArgs[0][i] == '"' && l != -1 && r == -1) r = i;
		if (commandArgs[0][i] == '"' && l == -1) l = i;
	}
	
	for (int i = 0; i < commandArgs[0].size(); i++) {
		if (i < l || i > r) errPlaces.push_back(i + 1 + commandName.size());
	}

	if (errPlaces.empty()) {
		return true;
	}
	return false;
};


string Echo::trimmedBody() {
	string trimmed = "";
	for (int i = 1; i < commandArgs[0].size() - 1; i++) trimmed += commandArgs[0][i];
	return trimmed;
}