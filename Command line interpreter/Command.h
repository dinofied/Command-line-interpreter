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
	RedirectionInfo getRedirectionInfo();

protected:
	iostream* inputStream;
	iostream* outputStream;
	RedirectionInfo redInfo;
	string commandName;
	vector<string> commandArgs;



	Command(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, IOStreamInfo ioInfo) {
		this->commandName = commandName;
		this->commandArgs = commandArgs;
		this->redInfo = redInfo;
		this->inputStream = (iostream*)ioInfo.input;
		this->outputStream = (iostream*)ioInfo.output;
	};


};

