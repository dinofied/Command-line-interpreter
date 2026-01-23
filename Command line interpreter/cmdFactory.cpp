#include "cmdFactory.h"



Command* commandFactory::createCmd(ParsedCommand parsedCommand , PipeInfo pipeInfo, StreamManager& streamManager) {
	if (!parsedCommand.body.size()) {
		cout << "Nevalidan unos." << endl;
		return nullptr;
	}


	std::istream* input = &std::cin;
	std::ostream* output = &std::cout;
	IOStreamInfo ioInfo = { input, output };

	if (!Inspector::isValidSyntax(parsedCommand, ioInfo, pipeInfo, streamManager)) {
		return nullptr;
	}

	string commandName = parsedCommand.body[0];
	vector<string> commandArgs = std::vector<std::string>(parsedCommand.body.begin() + 1, parsedCommand.body.end());
	RedirectionInfo redInfo = parsedCommand.redirection;


	if (redInfo.inputFile != "") {
		ioInfo.input = streamManager.createIOStream(redInfo.inputFile);
	}
	if (redInfo.outputFile != "") {
		ioInfo.output = streamManager.createIOStream(redInfo.outputFile);
	}

	
	//silne nule su na mestu nekadasnjeg charCounta koji se trenutno ne koristi (error handling)
	if (commandName == "echo") {
		return (Echo*) new Echo(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "time") {
		return (Time*) new Time(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "date") {
		return (Date*) new Date(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "wc") {
		return (wordCount*) new wordCount(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "touch") {
		return (Touch*) new Touch(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "prompt") {
		return (Prompt*) new Prompt(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "batch") {
		return (Batch*) new Batch(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "truncate") {
		return (Truncate*) new Truncate(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "rm") {
		return (Rm*) new Rm(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "head") {
		return (Head*) new Head(commandName, commandArgs, redInfo, 0, ioInfo);
	}
	if (commandName == "tr") {
		return (Tr*) new Tr(commandName, commandArgs, redInfo, 0, ioInfo);
	}

	

	nameDoesntExsist(commandName, commandArgs);
	return nullptr;
};


void commandFactory::nameDoesntExsist(string commandName, vector<string> commandArgs) {

	cout << "Unknown command: " << commandName << endl;
	

};

