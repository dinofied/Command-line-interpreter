#include "CommandLineInterpreter.h"

void CommandLineInterpreter::run(std::istream& stream) {

	if (!stream) {
		cout << "Fajl nije pronadjen." << endl;
		return;
	}
	string temp;

	cout << CommandLineInterpreter::terminalInstance().getReadySign();
	while (std::getline(stream, temp)) {
		
		vector<string> pipes = Collector::collectorInstance().breakPipes(temp);

		for (int i = 0; i < pipes.size(); i++) {

			Command* newCmd = commandFactory::createCmd(Lexer::lexerInstance().divideWords(pipes[i]), pipes[i].size());
			if (newCmd) newCmd->execute();
			cout << endl;
			delete newCmd;

		}

		cout << '\n' << CommandLineInterpreter::terminalInstance().getReadySign();
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