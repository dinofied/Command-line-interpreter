#include "cmdFactory.h"



Command* commandFactory::createCmd(ParsedCommand parsedCommand, PipeInfo pipeInfo, StreamManager& streamManager, std::ostream& outputStream) {
	if (!parsedCommand.body.size()) {
		cout << "Nevalidan unos." << endl;
		return nullptr;
	}
	
	//hooking up default streams
	std::istream* input = &std::cin;
	std::ostream* output = &outputStream;
	IOStreamInfo ioInfo = { input, output };

	//semantic check and error description
	string errorText = Inspector::isValidSyntax(parsedCommand, ioInfo, pipeInfo, streamManager);
	if (errorText == "Null") {
		cout << "(PipeId: " << pipeInfo.pipeId << ") - " << "Unknown command: " << parsedCommand.body[0] << endl;
		return nullptr;
	}

	//checking for redirections and hooking them up
	if (parsedCommand.redirection.inputFile != "") {
		ioInfo.input = streamManager.createIOStream(parsedCommand.redirection.inputFile);
		if (ioInfo.input == nullptr) {
			cout << "Fajl ne postoji: " << parsedCommand.redirection.inputFile << endl;
			return nullptr;
		}
	}
	if (parsedCommand.redirection.outputFile != "") {
		ioInfo.output = streamManager.createIOStream(parsedCommand.redirection.outputFile);
		if (ioInfo.output == nullptr) {
			cout << "Fajl ne postoji: " << parsedCommand.redirection.outputFile << endl;
			return nullptr;
		}
	}

	//gathering command info
	CommandInfo cmdInfo;
	cmdInfo.body = parsedCommand.body;
	cmdInfo.redirection = parsedCommand.redirection;
	cmdInfo.ioInfo = ioInfo;
	cmdInfo.errInfo = errorText;


	//command creation
	if (parsedCommand.body[0] == "echo") {
		return (Echo*) new Echo(cmdInfo);
	}
	if (parsedCommand.body[0] == "time") {
		return (Time*) new Time(cmdInfo);
	}
	if (parsedCommand.body[0] == "date") {
		return (Date*) new Date(cmdInfo);
	}
	if (parsedCommand.body[0] == "wc") {
		return (wordCount*) new wordCount(cmdInfo);
	}
	if (parsedCommand.body[0] == "touch") {
		return (Touch*) new Touch(cmdInfo);
	}
	if (parsedCommand.body[0] == "prompt") {
		return (Prompt*) new Prompt(cmdInfo);
	}
	if (parsedCommand.body[0] == "batch") {
		return (Batch*) new Batch(cmdInfo);
	}
	if (parsedCommand.body[0] == "truncate") {
		return (Truncate*) new Truncate(cmdInfo);
	}
	if (parsedCommand.body[0] == "rm") {
		return (Rm*) new Rm(cmdInfo);
	}
	if (parsedCommand.body[0] == "head") {
		return (Head*) new Head(cmdInfo);
	}
	if (parsedCommand.body[0] == "tr") {
		return (Tr*) new Tr(cmdInfo);
	}
};



