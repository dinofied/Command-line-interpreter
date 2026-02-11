#include "Parser.h"

ParsedCommand Parser::parsedCommand(const std::vector<std::string>& tokens) {
	ParsedCommand result;
	bool inRedirects = false;

	for (int i = 0; i < tokens.size(); i++) {
		if (tokens[i] == "<") {
			inRedirects = true;
			if (i == tokens.size() - 1 || tokens[i + 1] == "<" || tokens[i + 1] == ">" || tokens[i + 1] == ">>") {
				return { {"error", "Nedovoljno argumenata za redirekciju \"<\"."} };
			}
			if (result.redirection.hasInput == true) {
				return { {"error", "Visak redirekcija za unos."}};
			}
			else result.redirection.hasInput = true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.inputFile = tokens[i + 1];
				i ++;
			}	
			else {
				return { {"error", "Nevalidan argument za redirekciju \"<\"."} };
			}
		}
		else if (tokens[i] == ">") {
			inRedirects = true;
			if (i == tokens.size() - 1 || tokens[i + 1] == "<" || tokens[i + 1] == ">" || tokens[i + 1] == ">>") {
				return { {"error", "Nedovoljno argumenata za redirekciju \">\"."} };
			}
			if (result.redirection.hasOutput == true || result.redirection.hasAppend == true) {
				return { {"error", "Visak redirekcija za ispis."} };
			}
			else result.redirection.hasOutput = true;
			if (Command::isArgFile(tokens[i + 1])) { 
				result.redirection.outputFile = tokens[i + 1];
				i++;
			}
			else {
				return { {"error", "Nevalidan argument za redirekciju \">\"."} };
			}
		}
		else if (tokens[i] == ">>") {
			inRedirects = true;
			if (i == tokens.size() - 1 || tokens[i + 1] == "<" || tokens[i + 1] == ">" || tokens[i + 1] == ">>") {
				return { {"error", "Nedovoljno argumenata za redirekciju \">>\"."} };
			}
			if (result.redirection.hasOutput == true || result.redirection.hasAppend == true) {
				return { {"error", "Nedovoljno argumenata za redirekciju \">>\"."} };
			}
			else result.redirection.hasAppend = true;
			if (Command::isArgFile(tokens[i + 1])) {
				result.redirection.outputFile = tokens[i + 1];
				i++;
			}
			else {
				return { {"error", "Nevalidan argument za redirekciju \">>\"."} };
			}
		} else if (inRedirects) {
			return { {"error", "Previse argumenata uneto nakon ulaska u redirekciju."}};
		}
		


		if (!inRedirects) result.body.push_back(tokens[i]);
	}

	return result;
};
