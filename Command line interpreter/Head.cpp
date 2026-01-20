#include "Head.h"


void Head::runCommand() {
	int lineCount = stoi(commandArgs[0].substr(1, commandArgs[0].size() - 1));
	vector<string> out;

	if (isArgFile(commandArgs[1])) {
		std::ifstream file(commandArgs[1]);

		string temp;
		while (lineCount-- > 0 && getline(file, temp)) {
			out.push_back(temp);
		}
	}
	else {
		string temp;
		while (lineCount-- > 0 && getline(cin, temp)) {
			out.push_back(temp);
		}
	}

	for (int i = 0; i < out.size(); i++) {
		std::cout << out[i] << endl;
	}

};

bool Head::isValidBody() {

	if (commandArgs[0].size() < 2 || commandArgs[0].size() > 6 || commandArgs[0][0] != '-') return false;
	for (int i = 1; i < commandArgs[0].size(); i++) {
		if (commandArgs[0][i] < 48 || commandArgs[0][i] > 57) return false;
	}
	if (commandArgs.size() == 2) {
		if (!isArgFile(commandArgs[1])) return false;
	}

	return true;
};

void Head::errReport() {

	if (commandArgs.size() > 2) {
		std::cout << "Uneto previse argumenata." << endl;
	}
	else if (commandArgs.size() < 1) {
		std::cout << "Uneto premalo argumenata." << endl;
	}
	else std::cout << "Greska pri unosu argumenata komande:" << endl;

	std::cout << Command::toString() << std::endl;
	Command::errPlacesReport();

};