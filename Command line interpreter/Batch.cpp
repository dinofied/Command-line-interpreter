#include "Batch.h"

void Batch::runCommand() {

	std::ifstream batchInput(commandArgs[0]);

	CommandLineInterpreter::terminalInstance().isBatchSwitch();
	CommandLineInterpreter::terminalInstance().run(batchInput);
	CommandLineInterpreter::terminalInstance().isBatchSwitch();
};

bool Batch::isValidBody() {
	if (commandArgs.size() != 1) return false;
	if (Command::isLastArgFile()) return true;
	return false;
};

void Batch::errReport() {
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