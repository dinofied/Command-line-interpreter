#include "Parser.h"

ParsedCommand Parser::parsedCommand(const std::vector<std::string>& tokens) {
	ParsedCommand result;
	bool inRedirects = false;

	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "<") {
			inRedirects = true;
			if (i == tokens.size() - 1 || tokens[i + 1] == "<" || tokens[i + 1] == ">" || tokens[i + 1] == ">>") {
				return { {"error 1"} };
			}
			if (result.redirection.hasInput == true) {
				return { {"error 2"} };
			}
			else result.redirection.hasInput = true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.inputFile = tokens[i + 1];
				i ++;
			}	
			else {
				return { {"error 3"}};
			}
		}
		else if (tokens[i] == ">") {
			inRedirects = true;
			if (i == tokens.size() - 1 || tokens[i + 1] == "<" || tokens[i + 1] == ">" || tokens[i + 1] == ">>") {
				return { {"error 4"} };
			}
			if (result.redirection.hasOutput == true || result.redirection.hasAppend == true) {
				return { {"error 5"} };
			}
			else result.redirection.hasOutput = true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.outputFile = tokens[i + 1];
				i++;
			}
			else {
				return { {"error 6"} };
			}
		}
		else if (tokens[i] == ">>") {
			inRedirects = true;
			if (i == tokens.size() - 1 || tokens[i + 1] == "<" || tokens[i + 1] == ">" || tokens[i + 1] == ">>") {
				return { {"error 7"} };
			}
			if (result.redirection.hasOutput == true || result.redirection.hasAppend == true) {
				return { {"error 8"} };
			}
			else result.redirection.hasAppend = true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.outputFile = tokens[i + 1];
				i++;
			}
			else {
				return { {"error 9"} };
			}
		} else if (inRedirects) {
			return { {"error 10"} };
		}
		


		if (!inRedirects) result.body.push_back(tokens[i]);
	}


	return result;
};