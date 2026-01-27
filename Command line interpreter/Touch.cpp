#include "Touch.h"


void Touch::runCommand() {
	std::ifstream test(commandArgs[0]);
	if (test) {
		std::cout << "Fajl vec postoji:" << std::endl;
		std::cout << commandName << " ";
		for (int i = 0; i < commandArgs.size(); i++) {
			std::cout << commandArgs[i];
			if (i != commandArgs.size() - 1) std::cout << " ";
		}
		std::cout << std::endl;
		return;
	}

	std::ofstream newFile(commandArgs[0]);

};
