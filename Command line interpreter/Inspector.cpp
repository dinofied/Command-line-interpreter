#include "Inspector.h"

string Inspector::getNextToken(vector<string>& tokens, int tokenId) {
	if (tokenId < tokens.size()) {
		return tokens[tokenId];
	} 
	else {
		return "";
	}

};

bool Inspector::isValidSyntax(ParsedCommand& parsedCommand, IOStreamInfo& ioInfo, PipeInfo pipeInfo) {
	int it = 0;
	string token = getNextToken(parsedCommand.body, it++);

	if (token == "echo") {
		token = getNextToken(parsedCommand.body, it++);
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return false;
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = StreamManager::streamManagerInstance().createIOStream(token);
		}

		return true;
	}
}