#include "CommandLineInterpreter.h"

void CommandLineInterpreter::run(std::istream& input, std::ostream& output, bool inBatch) {

	if (!input) {
		std::cout << "Fajl nije pronadjen." << endl;
		return;
	}
	if (!inBatch) std::cout << CommandLineInterpreter::terminalInstance().getReadySign();

	string temp;
	while (getline(input, temp)) {
		
		StreamManager streamManager;
		vector<string> pipes = Collector::breakPipes(temp);
		vector<Command*> commands;
		
		for (size_t i = 0; i < pipes.size(); i++) {
			commands.push_back(commandFactory::createCmd(Parser::parsedCommand(Lexer::divideWords(pipes[i])), { i, pipes.size()}, streamManager, output));
		}

		//checking if the created command exists 
		bool hasError = false;
		for (int i = 0; i < commands.size(); i++) {
			if (commands[i] == nullptr) {
				hasError = true;
				continue;
			}
			else if (commands[i]->getErrInfo() != "valid") {
				if (!hasError) cout << "Errors:\n";
				if (hasError) cout << "\n";
				cout << "(PipeId: " << i << ") - " << commands[i]->getErrInfo();
				hasError = true;
			}
		}

		if (!hasError) {
			vector<stringstream*> pipeStreams;

			for (int i = 0; i < commands.size() - 1; i++) {
				pipeStreams.push_back(streamManager.createStringStream());
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
				commands[i]->runCommand();
				if (i != commands.size() - 1) std::cout << endl;
			}
			delete commands[i];
		}

		
		if (!inBatch) {
			std::cout << endl;
			std::cout << CommandLineInterpreter::terminalInstance().getReadySign();
		}
	}
	
}

void CommandLineInterpreter::setReadySign(std::string newSign) {

	this->readySign = newSign;
}

std::string CommandLineInterpreter::getReadySign() {

	return readySign + ' ';
}
