#include "CommandLineInterpreter.h"

void CommandLineInterpreter::run() {

	std::ifstream file("cmdTests.txt");
	if (!file) {
		cout << "nema fajla" << endl;
		return;
	}
	string temp;

	while (std::getline(file, temp)) {
		cout << CommandLineInterpreter::terminalInstance().getReadySign() << " ";

		Command* newCmd = commandFactory::createCmd(Lexer::lexerInstance().divideWords(temp), Lexer::lexerInstance().getCharCount());
		if (!newCmd) continue;
		else newCmd->execute();

		delete newCmd;
	}
}


void CommandLineInterpreter::setReadySign(std::string newSign) {

	this->readySign = newSign;
}

std::string CommandLineInterpreter::getReadySign() {

	return readySign;

}