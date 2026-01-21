#include "StreamManager.h"


void StreamManager::deleteAllPointers() {

	for (auto it : ioStreams) {
		delete it;
	}

	for (auto it : stringStreams) {
		delete it;
	}

};

fstream* StreamManager::createIOStream(string fileName) {
	fstream* newStream = new fstream(fileName);
	ioStreams.push_back(newStream);
	return newStream;
}