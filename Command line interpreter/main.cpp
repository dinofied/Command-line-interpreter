#include "CommandLineInterpreter.h"

//notes:

int main() {

	CommandLineInterpreter::terminalInstance().run(std::cin, std::cout, false);
	
}