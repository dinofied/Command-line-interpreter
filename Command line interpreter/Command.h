#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;


//base klasa za sve komande
//sadrzi osnovne stvari kao: ime komande, argumente komande, broj karaktera i ima apstraktne i genericne metode

class Command {
public:
	virtual ~Command() = default;

	virtual void execute();
	string toString();

	virtual string getName();
	virtual vector<string> getArgs();

private:

protected:
	string commandName;
	vector<string> commandArgs;
	int charCount;
	bool argIsFile;

	//pri trazenju gresaka njihov indeks se upisuje ovde
	vector<int> errPlaces;


	Command(string commandName, vector<string> commandArgs, int charCount) {
		errPlaces = {};
		argIsFile = false;
		this->commandName = commandName;
		this->commandArgs = commandArgs;
		this->charCount = charCount;
	};

	virtual void runCommand() = 0;
	
	virtual bool isValidBody() = 0;

	virtual void errReport() = 0;

	//gnerican ispis znakova "^" ispod greski
	void errPlacesReport();

};

