#include "Collector.h"

std::vector<std::string> Collector::breakPipes(std::string inputLine) {
	std::vector<std::string> pipes;
	std::string pipe = "";
	bool inQuotationMarks = false;

	for (int i = 0; i < inputLine.size(); i++) {
		if (inputLine[i] == '"') {
			if (inQuotationMarks) inQuotationMarks = false;
			else inQuotationMarks = true;
		}

		if (inputLine[i] == '|' && !inQuotationMarks) {
			pipes.push_back(pipe);
			pipe = "";
			continue;
		}

		pipe += inputLine[i];
	}

	pipes.push_back(pipe);
	return pipes;
}