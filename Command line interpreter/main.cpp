#include <iostream>
#include <string>
#include <fstream>
#include "cmdFactory.h"
#include "Echo.h"
#include "readySign.h"
#include "Lexer.h"
using namespace std;

//notes:


int main() {

	std::ifstream file("cmdTests.txt");
	if (!file) {
		cout << "nema fajla" << endl;
		return 1;
	}
	
	string temp;

	while (std::getline(file, temp)) {
		cout << readySign::signInstance().getReadySign() << " ";

		Command* newCmd = commandFactory::factoryInstance().createCmd(Lexer::lexerInstance().divideWords(temp));
		if (!newCmd) continue;
		else newCmd->execute();

		delete newCmd;
	}
}