#include "Inspector.h"

string Inspector::getNextToken(vector<string>& tokens, int tokenId) {
	if (tokenId < tokens.size()) {
		return tokens[tokenId];
	} 
	else {
		return "";
	}

};

bool Inspector::isValidSyntax(ParsedCommand& parsedCommand, IOStreamInfo& ioInfo, PipeInfo pipeInfo, StreamManager& streamManager) {
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
			ioInfo.input = streamManager.createIOStream(token);
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
			ioInfo.input = streamManager.createIOStream(token);
		}

		return true;
		
	}

	else if (token == "time" || token == "date") {
		if (parsedCommand.body.size() > 1) return false;
		if (parsedCommand.redirection.hasInput) return false;
		if (pipeInfo.pipeId != 0) return false;
		return true;
	}

	else if (token == "prompt") {
		token = getNextToken(parsedCommand.body, it++);
		if (parsedCommand.body.size() != 2) return false;
		if (!Command::isArgText(token)) return false;
		if (parsedCommand.redirection.hasAppend || parsedCommand.redirection.hasInput || parsedCommand.redirection.hasOutput) return false;
		if (pipeInfo.pipeCount != 1) return false;
	}

	else if (token == "head") {
		token = getNextToken(parsedCommand.body, it++);
		if (parsedCommand.body.size() < 2 || parsedCommand.body.size() > 3) return false;
		if (parsedCommand.body.size() == 3 || pipeInfo.pipeId != 0) {
			if (parsedCommand.redirection.hasInput || parsedCommand.redirection.hasAppend) return false;
		}
		if (token[0] != '-') return false;
		for (int i = 1; i < token.size(); i++) {
			if (token[i] < 48 || token[i] > 57) return false;
		}
		token = getNextToken(parsedCommand.body, it++);
		if (token == "") return true;
		if (Command::isArgText(token)) return false;
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return false;
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = streamManager.createIOStream(token);
		}

		return true;
	}

	else if (token == "batch") {
		token = getNextToken(parsedCommand.body, it++);
		if (pipeInfo.pipeCount != 1) return false;
		if (parsedCommand.body.size() != 2) return false;
		if (!Command::isArgFile(token)) return false;
		if (parsedCommand.redirection.hasAppend || parsedCommand.redirection.hasInput || parsedCommand.redirection.hasOutput) return false;
		parsedCommand.redirection.hasInput = true;
		ioInfo.input = streamManager.createIOStream(token);

		return true;
		
	}

}