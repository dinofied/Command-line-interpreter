#include "Batch.h"

void Batch::runCommand() {


	//slucaj gde je argument text + provera da li fajl postoji ako je argument fajl
	if (commandArgs.size()) {
		if (Command::isArgText(commandArgs[0])) {
			cout << "Los unos za batch." << endl;
			return;
		}
		if (Command::isArgFile(commandArgs[0])) {
			std::ifstream test(commandArgs[0]);
			if (!test) {
				std::cout << "Fajl ne postoji:" << endl;
				std::cout << commandArgs[0] << endl;
				return;
			}
		}
	}

	CommandLineInterpreter::terminalInstance().run(*inputStream, *outputStream, true);

	cin.clear();
};

bool Batch::isValidBody() {
	return true;
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