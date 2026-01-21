#include "Parser.h"

ParsedCommand Parser::parsedCommand(const std::vector<std::string>& tokens) {
	ParsedCommand result;
	bool inRedirects = false;

	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "<") {
			inRedirects = true;
			if (result.redirection.hasInput == true) {
				return {};
			}
			else result.redirection.hasInput == true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.inputFile = tokens[i + 1];
				i++;
			}	
			else {
				return {};
			}
		}
		else if (tokens[i] == ">") {
			inRedirects = true;
			if (result.redirection.hasOutput == true || result.redirection.hasAppend == true) {
				return {};
			}
			else result.redirection.hasOutput = true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.outputFile = tokens[i + 1];
				i++;
			}
			else {
				return {};
			}
		}
		else if (tokens[i] == ">>") {
			inRedirects = true;
			if (result.redirection.hasOutput == true || result.redirection.hasAppend == true) {
				return {};
			}
			else result.redirection.hasAppend = true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.outputFile = tokens[i + 1];
				i++;
			}
			else {
				return {};
			}
		}


		if (!inRedirects) result.body.push_back(tokens[i]);
	}


	return result;
};