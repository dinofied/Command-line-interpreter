#include "Batch.h"

void Batch::runCommand() {

	//provera da li fajl za upis postoji
	if (redInfo.inputFile != "") {
		std::fstream check(redInfo.inputFile);
		if (!check) {
			cout << "Fajl ne posotji." << endl;
			return;
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