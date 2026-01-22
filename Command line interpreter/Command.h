#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "structs.h"

using namespace std;

//base klasa za sve komande
//sadrzi osnovne stvari kao: ime komande, argumente komande, broj karaktera i ima apstraktne i genericne metode

class Command {
public:
	virtual ~Command() = default;

	virtual void execute();
	string toString();
	static bool isArgFile(string arg);
	static bool isArgText(string arg);
	static string trimmedText(string arg);

	virtual string getName();
	virtual vector<string> getArgs();
	RedirectionInfo getRedirectionInfo();

	void switchInputStream(iostream* newInput);
	void switchOutputStream(iostream* newOutput);

private:

protected:
	iostream* inputStream;
	iostream* outputStream;
	RedirectionInfo redInfo;
	string commandName;
	vector<string> commandArgs;
	int charCount;

	//pri trazenju gresaka njihov indeks se upisuje ovde
	vector<int> errPlaces;


	Command(string commandName, vector<string> commandArgs, RedirectionInfo redInfo, int charCount, IOStreamInfo ioInfo) {
		errPlaces = {};
		this->commandName = commandName;
		this->commandArgs = commandArgs;
		this->charCount = charCount;
		this->redInfo = redInfo;
		this->inputStream = (iostream*)ioInfo.input;
		this->outputStream = (iostream*)ioInfo.output;
	};

	virtual void runCommand() = 0;
	
	virtual bool isValidBody() = 0;

	virtual void errReport() = 0;

	//genericne funkcije
	void errPlacesReport();

};

