#include "Tr.h"


void Tr::runCommand() {
	//namesta da li ce fajl da se overwrituje ili appenduje
	std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
	if (redInfo.outputFile != "") {

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}
	
	if (Command::isArgText(commandArgs[0])) {
		string with = "";
		if (commandArgs.size() == 3) with = Command::trimmedText(commandArgs[2]);
		*outputStream << editLine(Command::trimmedText(commandArgs[0]), commandArgs[1], with) << endl;
		return;
	}

	//ucitava podatke u listu i obradjuje ih 
	string temp;
	vector<string> input;
	while (getline(*inputStream, temp)) {
		string with = "";
		string what;
		
		if (Command::isArgFile(commandArgs[0])) {
			what = commandArgs[1];
			if (commandArgs.size() == 3) with = Command::trimmedText(commandArgs[2]);
		}
		else {
			what = commandArgs[0];
			if (commandArgs.size() == 2) with = Command::trimmedText(commandArgs[1]);
		}
		input.push_back(editLine(temp, what, with));
	}

	int counter = 0;
	for (auto& token : input) {
		if (counter != 0) *outputStream << endl;
		*outputStream << token;
		counter++;
	}

	cin.clear();

};

string Tr::editLine(string input, string what, string with) {
	if (what == "-\"\"") return input;
	what = what.substr(2, what.size() - 3);
	int sizeWhat = what.size();

	string edited = "";
	for (int i = 0; i < input.size() - what.size() + 1; i++) {
		if (input[i] == what[0]) {
			string temp = input.substr(i, what.size());
			if (temp == what) {
				edited += with;
				i += what.size() -1;
				continue;
			}
		}
		edited += input[i];
	}

	return edited;
}
