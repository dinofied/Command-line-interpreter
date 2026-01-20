#include "Prompt.h"


void Prompt::runCommand() {

	CommandLineInterpreter::terminalInstance().setReadySign(trimmedText(commandArgs[0]));

};

bool Prompt::isValidBody() {
	if (commandArgs.size() != 1) return false;
	if (Command::isArgText(commandArgs[0])) return true;
	return false;
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