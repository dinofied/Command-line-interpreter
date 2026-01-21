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
		vector<Command*> commands;
		
		for (size_t i = 0; i < pipes.size(); i++) {
			commands.push_back(commandFactory::createCmd(Parser::parserInstance().parsedCommand(Lexer::lexerInstance().divideWords(pipes[i])), temp.size()));
		}

		bool allowedInput, allowedOutput;
		bool hasError = false;
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == nullptr) {
				hasError = true;
				break;
			}

			if (i == 0) allowedInput = true;
			else allowedInput = false;
			if (i == commands.size() - 1) allowedOutput = true;
			else allowedOutput = false;

			//trenutno ne radi zbog izmene u poljima za redirekciju komande, popraviti sa stream checkovima
			if (commands[i]->getRedirectionInfo().hasInput && !allowedInput) {
				cout << "Greska: Ne moze se izvrsiti redirekcija ulaza na komandama koje nisu prve u nizu." << endl;
				hasError = true;
			}
			if ((commands[i]->getRedirectionInfo().hasOutput || commands[i]->getRedirectionInfo().hasAppend) && !allowedOutput) {
				cout << "Greska: Ne moze se izvrsiti redirekcija izlaza na komandama koje nisu poslednje u nizu." << endl;
				hasError = true;
			}
		}


		for (size_t i = 0; i < commands.size(); i++) {
			if (!hasError) {
				commands[i]->execute();
				if (i != commands.size() - 1) cout << endl;
			}
			delete commands[i];
		}

		
		StreamManager::streamManagerInstance().deleteAllPointers();
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