#include "Prompt.h"


void Prompt::runCommand() {

	CommandLineInterpreter::terminalInstance().setReadySign(trimmedText(commandArgs[0]));

};

bool Prompt::isValidBody() {
	return true;
};

void Prompt::errReport() {

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