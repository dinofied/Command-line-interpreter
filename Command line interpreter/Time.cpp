#include "Time.h"

void Time::runCommand() {
	

};

bool Time::isValidBody() {

	if (commandArgs.size()) return false;
	return true;
};

void Time::errReport() {
	if (commandArgs.size()) {
		std::cout << "Uneto previse argumenata." << endl;
		std::cout << getCommand() << endl;

	}
};
