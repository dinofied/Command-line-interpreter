#include "CommandLineInterpreter.h"

void CommandLineInterpreter::run(std::istream& stream) {

	if (!stream) {
		cout << "Fajl nije pronadjen." << endl;
		return;
	}
	string temp;

	cout << CommandLineInterpreter::terminalInstance().getReadySign();
	while (std::getline(stream, temp)) {
		

		Command* newCmd = commandFactory::createCmd(Lexer::lexerInstance().divideWords(temp), temp.size());
		if (newCmd) newCmd->execute();

		if (!newCmd || (newCmd && (newCmd->getName() != "Batch"))) {
			if (newCmd) cout << endl;
			cout << CommandLineInterpreter::terminalInstance().getReadySign();
		}

		delete newCmd;
	}
}


void CommandLineInterpreter::setReadySign(std::string newSign) {

	this->readySign = newSign;
}

std::string CommandLineInterpreter::getReadySign() {

	if (!isBatch) return readySign + ' ';
	else return "";
}

void CommandLineInterpreter::isBatchSwitch() {
	if (this->isBatch) isBatch = false;
	else isBatch = true;
}