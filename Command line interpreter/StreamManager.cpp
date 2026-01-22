#include "StreamManager.h"


void StreamManager::deleteAllPointers() {

	for (auto it : ioStreams) {
		delete it;
	}

	for (auto it : stringStreams) {
		delete it;
	}
	ioStreams.clear();
	stringStreams.clear();
	
};

fstream* StreamManager::createIOStream(string fileName) {
	if (Command::isArgFile(fileName)) {
		fstream* newStream = new fstream(fileName);
		ioStreams.push_back(newStream);
		return newStream;
	}
}

stringstream* StreamManager::createStringStream() {
	stringstream* newStream = new stringstream();
	stringStreams.push_back(newStream);
	return newStream;
};