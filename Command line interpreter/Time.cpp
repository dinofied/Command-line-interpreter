#include "Time.h"

void Time::runCommand() {
	std::time_t now = std::time(nullptr);
	std::tm localTime{};
	localtime_s(&localTime, &now);

	std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
	if (redInfo.outputFile != "") {
		std::ifstream checkExistence(redInfo.outputFile);
		if (!checkExistence) {
			cout << "Fajl ne postoji: " << redInfo.outputFile << endl;
			return;
		}

		if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
		if (redInfo.hasAppend) outputStream = &fs;
	}


	*outputStream << twoDigits(localTime.tm_hour) << ":";
	*outputStream << twoDigits(localTime.tm_min) << ":";
	*outputStream << twoDigits(localTime.tm_sec) << '\n';

};

string Time::twoDigits(int i) {
	string digits = "";
	if (i < 10) digits += '0';
	digits += to_string(i);
	return digits;
};

bool Time::isValidBody() {

	return true;

};

void Time::errReport() {
	if (commandArgs.size()) {
		std::cout << "Uneto previse argumenata." << endl;
		std::cout << toString() << endl;

	}
};
