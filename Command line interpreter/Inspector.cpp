#include "Inspector.h"

string Inspector::getNextToken(vector<string> tokens, int& tokenId) {
	tokenId++;
	if (tokenId < tokens.size()) {
		return tokens[tokenId];
	}
	else {
		return "";
	}

};

bool Inspector::isValidSyntax(ParsedCommand parsedCommand, IOStreamInfo& ioInfo) {
	int iterator = 0;
	string token = getNextToken(parsedCommand.body, iterator);


	if (token == "echo") {
		token = getNextToken(parsedCommand.body, iterator);
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return false;
			}
			ioInfo.input = StreamManager::streamManagerInstance().createIOStream(token);
		}

		return true;
	}
}