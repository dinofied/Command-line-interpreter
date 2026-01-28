#include "Date.h"

void Date::runCommand() {
    std::time_t now = std::time(nullptr);
    std::tm localTime{};
    localtime_s(&localTime, &now); 

    //namesta da li ce fajl da se overwrituje ili appenduje
    std::fstream fs(redInfo.outputFile, std::ios::out | std::ios::app);
    if (redInfo.outputFile != "") {

        if (redInfo.hasOutput)std::ofstream file(redInfo.outputFile);
        if (redInfo.hasAppend) outputStream = &fs;
    }

    *outputStream << twoDigits(localTime.tm_mday) << '.';
    *outputStream << twoDigits(localTime.tm_mon + 1) << '.';
    *outputStream << (localTime.tm_year + 1900) << '.';
}

string Date::twoDigits(int i) {
    string digits = "";
    if (i < 10) digits += '0';
    digits += to_string(i);
    return digits;
};