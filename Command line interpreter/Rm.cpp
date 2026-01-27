#include "Rm.h"


void Rm::runCommand() {

	if (std::remove(commandArgs[0].c_str()) != 0){
		std::cout << "Fajl \"" << commandArgs[0] << "\" ne postoji." << std::endl;
	};

};
