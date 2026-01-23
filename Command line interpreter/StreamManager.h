#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "structs.h"
#include "Command.h"

using namespace std;

class StreamManager {
public:
	

	~StreamManager();

	void deleteAllPointers();

	fstream* createIOStream(string fileName);
	stringstream* createStringStream();


private:
	vector<fstream*> ioStreams;
	vector<stringstream*> stringStreams;

};

