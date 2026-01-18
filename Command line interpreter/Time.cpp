#include "Time.h"

void Time::runCommand() {
	std::time_t now = std::time(nullptr);
	std::tm localTime{};
	localtime_s(&localTime, &now);

	auto print2digits = [](int n) {
		if (n < 10) std::cout << '0';
		std::cout << n;
		};

	print2digits(localTime.tm_hour);
	std::cout << ':';
	print2digits(localTime.tm_min);
	std::cout << ':';
	print2digits(localTime.tm_sec);
	std::cout << '\n';

};

bool Time::isValidBody() {

	return !commandArgs.size();

};

void Time::errReport() {
	if (commandArgs.size()) {
		std::cout << "Uneto previse argumenata." << endl;
		std::cout << toString() << endl;

	}
};
