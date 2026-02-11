#include "Batch.h"

void Batch::runCommand() {

	//namesta da li ce fajl da se overwrituje ili appenduje
	std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
	if (redInfo.outputFile != "") {

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}

	//slucaj gde je argument text
	if (commandArgs.size()) {
		if (Command::isArgText(commandArgs[0])) {
			cout << "Los unos za batch." << endl;
			return;
		}
	}
	 
	
	CommandLineInterpreter::terminalInstance().run(*inputStream, *outputStream, true);

	cin.clear();
};
