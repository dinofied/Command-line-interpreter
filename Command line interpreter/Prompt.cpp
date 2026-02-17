#include "Prompt.h"


void Prompt::runCommand() {

	CommandLineInterpreter::terminalInstance().setReadySign(trimmedText(commandArgs[0]));

};
