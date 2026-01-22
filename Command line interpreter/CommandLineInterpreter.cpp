#include "CommandLineInterpreter.h"

void CommandLineInterpreter::run(std::istream& stream) {

	if (!stream) {
		std::cout << "Fajl nije pronadjen." << endl;
		return;
	}
	string temp;

	std::cout << CommandLineInterpreter::terminalInstance().getReadySign();
	while (getline(stream, temp)) {
		

		vector<string> pipes = Collector::collectorInstance().breakPipes(temp);
		vector<Command*> commands;
		
		for (size_t i = 0; i < pipes.size(); i++) {
			commands.push_back(commandFactory::createCmd(Parser::parserInstance().parsedCommand(Lexer::lexerInstance().divideWords(pipes[i])), { i, pipes.size()}));
		}

		bool hasError = false;
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == nullptr) {
				std::cout << "Sintaksna greska u pipu broj: " << i + 1 << endl;
				hasError = true;
				break;
			}
			bool allowedInput = false, allowedOutput = false;
			if (i == 0) allowedInput = true;
			if (i == commands.size() - 1) allowedOutput = true;


			if (allowedOutput == false && commands[i]->getRedirectionInfo().hasOutput) {
				std::cout << "Izlaz se sme preusmeriti samo na poslednjoj komandi." << endl;
				hasError = true;
			}

			if (allowedInput == false && (commands[i]->getRedirectionInfo().hasInput || commands[i]->getRedirectionInfo().hasAppend)) {
				std::cout << "Ulaz se sme preusmeriti samo na prvoj komandi." << endl;
				hasError = true;
			}
			
		}

		if (!hasError) {
			vector<stringstream*> pipeStreams;

			for (int i = 0; i < commands.size() - 1; i++) {
				pipeStreams.push_back(StreamManager::streamManagerInstance().createStringStream());
			}

			for (int i = 0; i < commands.size(); i++) {
				if (i != 0) {
					commands[i]->switchInputStream(pipeStreams[i - 1]);
				}
				if (i != commands.size() - 1) {
					commands[i]->switchOutputStream(pipeStreams[i]);
				}
			}
		}

		for (size_t i = 0; i < commands.size(); i++) {
			if (!hasError) {
				commands[i]->execute();
				if (i != commands.size() - 1) std::cout << endl;
			}
			delete commands[i];
		}

		
		StreamManager::streamManagerInstance().deleteAllPointers();
		std::cout << '\n' << CommandLineInterpreter::terminalInstance().getReadySign();
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