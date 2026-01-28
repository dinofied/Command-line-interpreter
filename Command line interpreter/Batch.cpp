#include "Batch.h"

void Batch::runCommand() {


	//slucaj gde je argument text + provera da li fajl postoji ako je argument fajl
	if (commandArgs.size()) {
		if (Command::isArgText(commandArgs[0])) {
			cout << "Los unos za batch." << endl;
			return;
		}
	}

	CommandLineInterpreter::terminalInstance().run(*inputStream, *outputStream, true);

	cin.clear();
};
