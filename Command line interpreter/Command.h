#pragma once
#include <iostream>
#include <fstream>
#include "structs.h"

using namespace std;

//base klasa za sve komande
//sadrzi osnovne stvari kao: ime komande, argumente komande, broj karaktera i ima apstraktne i genericne metode

class Command {
public:
	virtual ~Command() = default;

	virtual void runCommand() = 0;

	//input switching
	void switchInputStream(iostream* newInput);
	void switchOutputStream(iostream* newOutput);

	//helper functions
	static bool isArgFile(string arg);
	static bool isArgText(string arg);
	static string trimmedText(string arg);
	virtual string getName();
	virtual vector<string> getArgs();
	string getErrInfo();
	RedirectionInfo getRedirectionInfo();

protected:
	iostream* inputStream;
	iostream* outputStream;
	RedirectionInfo redInfo;
	string commandName;
	vector<string> commandArgs;
	string errInfo;

	Command(CommandInfo cmdInfo) {
		this->commandName = cmdInfo.body[0];
		this->commandArgs = std::vector<std::string>(cmdInfo.body.begin() + 1, cmdInfo.body.end());
		this->redInfo = cmdInfo.redirection;
		this->inputStream = (iostream*)cmdInfo.ioInfo.input;
		this->outputStream = (iostream*)cmdInfo.ioInfo.output;
		this->errInfo = cmdInfo.errInfo;
	};
};

