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
		if (parsedCommand.body.size() > 2) return false;
		token = getNextToken(parsedCommand.body, it++);
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return false;
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = StreamManager::streamManagerInstance().createIOStream(token);
		}
		if (token != "" && Command::isArgText(token) && pipeInfo.pipeId != 0) return false;

		return true;
	}

	else if (token == "wc") {
		if (parsedCommand.body.size() > 3 || parsedCommand.body.size() < 2) return false;
		token = getNextToken(parsedCommand.body, it++);
		if (token != "-c" && token != "-w") {
			return false;
		}
		token = getNextToken(parsedCommand.body, it++);
		if (!Command::isArgFile(token) && !Command::isArgText(token)) return false;
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return false;
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = StreamManager::streamManagerInstance().createIOStream(token);
		}

		return true;
		
	}


	else if (token == "time") {
		if (parsedCommand.body.size() > 1) return false;
		if (parsedCommand.redirection.hasInput) return false;
		if (pipeInfo.pipeId != 0) return false;
		return true;
	}
}