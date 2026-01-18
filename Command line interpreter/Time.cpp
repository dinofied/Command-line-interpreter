#include "Time.h"

void Time::runCommand() {
	

};

bool Time::isValidBody() {

	return !commandArgs.size();

};

void Time::errReport() {
	if (commandArgs.size()) {
		std::cout << "Uneto previse argumenata." << endl;
		std::cout << toString() << endl;

	}
};
