#include "Echo.h"
#include <iostream>
#include <fstream>
using namespace std;


void Echo::runCommand() {

	string temp;
	while (getline(*inputStream, temp)){
		*outputStream << temp << endl;
	}
}


void Echo::errReport() {

	cout << "Greska: Nevalidni argumenti za echo komandu." << endl;

};

bool Echo::isValidBody() {
	return true;
};