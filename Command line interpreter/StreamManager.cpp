#include "StreamManager.h"


void StreamManager::deleteAllPointers() {

	for (auto it : ioStreams) {
		if (it) {
			if (it->is_open()) it->close();
			delete it;
		}
	}

	for (auto it : stringStreams) {
		delete it;
	}
	ioStreams.clear();
	stringStreams.clear();
	
};

fstream* StreamManager::createIOStream(string fileName) {
	if (Command::isArgFile(fileName)) {
		fstream* newStream = new fstream(fileName, std::ios::in | std::ios::out | std::ios::app);
		if (!newStream->is_open()) {
			delete newStream;
			return nullptr;
		}
		ioStreams.push_back(newStream);
		return newStream;
	}
	return nullptr;
}

stringstream* StreamManager::createStringStream() {
	stringstream* newStream = new stringstream();
	stringStreams.push_back(newStream);
	return newStream;
};

StreamManager::~StreamManager() {
	deleteAllPointers();
}