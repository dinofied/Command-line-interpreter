#include "CommandLineInterpreter.h"

void CommandLineInterpreter::run(std::istream& stream) {

	if (!stream) {
		cout << "Fajl nije pronadjen." << endl;
		return;
	}
	string temp;

	cout << CommandLineInterpreter::terminalInstance().getReadySign() << " ";
	while (std::getline(cin, temp)) {
		

		Command* newCmd = commandFactory::createCmd(Lexer::lexerInstance().divideWords(temp), Lexer::lexerInstance().getCharCount());
		if (!newCmd) continue;
		else newCmd->execute();

		delete newCmd;
		cout << endl;
		cout << CommandLineInterpreter::terminalInstance().getReadySign() << " ";
	}
}


void CommandLineInterpreter::setReadySign(std::string newSign) {

	this->readySign = newSign;
}

std::string CommandLineInterpreter::getReadySign() {

	return readySign;

}