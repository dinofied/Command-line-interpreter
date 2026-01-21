#pragma once
#include <vector>
#include <string>
#include "Pipe.h"


class Collector {
public:
	static Collector& collectorInstance() {
		static Collector instance;
		return instance;
	}

	static std::vector<std::string> breakPipes(std::string inputLine);

private:
	Collector() {};

	
};


