#include "Echo.h"
#include <iostream>
using namespace std;


void Echo::runCommand() {

	for (int i = 0; i < commandArgs.size(); i++) {
		std::cout << commandArgs[i];
		if (i != commandArgs.size() - 1) std::cout << " ";
	}
	std::cout << std::endl;
}


void Echo::errReport() {

	if (commandArgs.size() > 1) {
		std::cout << "Uneto previse argumenata." << endl;
	}
	else if (commandArgs.size() < 1) {
		std::cout << "Uneto premalo argumenata." << endl;
	}
	else std::cout << "Greska pri unosu argumenata komande:" << endl;

	std::cout << Command::getCommand() << std::endl;
	Command::errPlacesReport();

};

bool Echo::isValidBody() {
	if (commandArgs.size() != 1 ) return false;
	int l = -1, r = -1;

	for (int i = 0; i < commandArgs[0].size(); i++) {
		if (commandArgs[0][i] == '"' && l != -1 && r == -1) r = i;
		if (commandArgs[0][i] == '"' && l == -1) l = i;
	}
	
	for (int i = 0; i < commandArgs[0].size(); i++) {
		if (i < l || i > r) errPlaces.push_back(i + 1 + commandName.size());
	}

	if (errPlaces.size() == 0) {
		trimBody(l, r);
		return true;
	}
	return false;
};


void Echo::trimBody(int l, int r) {
	string trimmed = "";
	for (int i = l + 1; i < r; i++) trimmed += commandArgs[0][i];
	commandArgs[0] = trimmed;
}