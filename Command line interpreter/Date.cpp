#include "Date.h"

void Date::runCommand() {
    std::time_t now = std::time(nullptr);
    std::tm localTime{};
    localtime_s(&localTime, &now); 

    auto print2digits = [](int n) {
        if (n < 10) std::cout << '0';
        std::cout << n;
        };

    print2digits(localTime.tm_mday);
    std::cout << '.';
    print2digits(localTime.tm_mon + 1);
    std::cout << '.';
    std::cout << (localTime.tm_year + 1900) << '.';
    std::cout << '\n';
}

bool Date::isValidBody() {

	return !commandArgs.size();

};

void Date::errReport() {
	if (commandArgs.size()) {
		std::cout << "Uneto previse argumenata." << endl;
		std::cout << toString() << endl;
	}
};