#include "Inspector.h"

string Inspector::getNextToken(vector<string>& tokens, int tokenId) {
	if (tokenId < tokens.size()) {
		return tokens[tokenId];
	} 
	else {
		return "";
	}

};

string Inspector::isValidSyntax(ParsedCommand& parsedCommand, IOStreamInfo& ioInfo, PipeInfo pipeInfo, StreamManager& streamManager) {
	int it = 0;
	string token = getNextToken(parsedCommand.body, it++);

	//pipe redirection validation for redirections
	bool allowedInput = false, allowedOutput = false;
	if (pipeInfo.pipeId == 0) allowedInput = true;
	if (pipeInfo.pipeId == pipeInfo.pipeCount - 1) allowedOutput = true;

	if (allowedOutput == false && (parsedCommand.redirection.hasOutput || parsedCommand.redirection.hasAppend)) {
		return "Izlaz se sme preusmeriti samo na poslednjoj komandi.";
	}
	if (allowedInput == false && (parsedCommand.redirection.hasInput)) {
		return "Ulaz se sme preusmeriti samo na prvoj komandi.";
	}

	//semantic validation
	if (token == "echo") {
		if (parsedCommand.body.size() > 2) return "Previse argumenata.";
		token = getNextToken(parsedCommand.body, it++);
		if (!Command::isArgFile(token) && !Command::isArgText(token)) return "Nevalidan argument: " + token;
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return "Konflikt unosa i redirekcije.";
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = streamManager.createIOStream(token);
		}
		if (token != "" && Command::isArgText(token) && pipeInfo.pipeId != 0) return "Komanda u pipe-u ne moze imati unos.";

		return "valid";
	}

	else if (token == "wc") {
		if (parsedCommand.body.size() > 3) return "Previse argumenata.";
		if (parsedCommand.body.size() < 2) return "Premalo argumenata.";
		token = getNextToken(parsedCommand.body, it++);
		if (token != "-c" && token != "-w") {
			return "Nevalidna opcija: " + token;
		}
		token = getNextToken(parsedCommand.body, it++);
		if (!Command::isArgFile(token) && !Command::isArgText(token)) return "Nevalidan argument: " + token;
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return "Konflikt unosa i redirekcije.";
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = streamManager.createIOStream(token);
		}
		if (token != "" && Command::isArgText(token) && pipeInfo.pipeId != 0) return "Komanda u pipe-u ne moze imati unos.";

		return "valid";
	}

	else if (token == "time" || token == "date") {
		if (parsedCommand.body.size() > 1) return "Previse argumenata.";
		if (parsedCommand.redirection.hasInput) return "Komanda ne moze imati input.";
		if (pipeInfo.pipeId != 0) return "Komanda ne moze biti u pipe-u.";
		return "valid";
	}

	else if (token == "prompt") {
		token = getNextToken(parsedCommand.body, it++);
		if (parsedCommand.body.size() != 2) return "Previse argumenata.";
		if (!Command::isArgText(token)) return "Unos komande moze biti iskljucivo argument pod navodnicima.";
		if (parsedCommand.redirection.hasAppend || parsedCommand.redirection.hasInput || parsedCommand.redirection.hasOutput) return "Komanda ne moze imati ni input ni output.";
		if (pipeInfo.pipeId != 0) return "Komanda ne moze biti u pipe-u.";
		return "valid";
	}

	else if (token == "head") {
		token = getNextToken(parsedCommand.body, it++);
		if (parsedCommand.body.size() < 2) return "Premalo argumenata.";
		if (parsedCommand.body.size() > 3) return "Previse argumenata.";
		if (token[0] != '-' || token[1] != 'n') return "Nevalidna opcija: " + token;
		for (int i = 2; i < token.size(); i++) {
			if (token[i] < 48 || token[i] > 57) return "Nevalidna opcija: " + token;
		}
		token = getNextToken(parsedCommand.body, it++);
		if (token == "") return "valid";
		if (Command::isArgText(token)) return "Nevalidan argument: " + token;
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return "Konflikt unosa i redirekcije.";
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = streamManager.createIOStream(token);
		}
		if (token != "" && Command::isArgText(token) && pipeInfo.pipeId != 0) return "Komanda u pipe-u ne moze imati unos.";
		return "valid";
	}

	else if (token == "batch") {
		if (parsedCommand.body.size() > 2) return "Previse argumenata.";
		token = getNextToken(parsedCommand.body, it++);
		if (!Command::isArgFile(token)) return "Nevalidan argument: " + token;
		if (Command::isArgFile(token)) {
			if (parsedCommand.redirection.hasInput) {
				return "Konflikt unosa i redirekcije.";
			}
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = streamManager.createIOStream(token);
		}
		if (token != "" && Command::isArgFile(token) && pipeInfo.pipeId != 0) return "Komanda u pipe-u ne moze imati unos.";
		if (pipeInfo.pipeId == 0 && parsedCommand.body.size() == 1 && !parsedCommand.redirection.hasInput) return "Komanda nema unos.";

		return "valid";
	}

	else if (token == "touch" || token == "rm" || token == "truncate") {
		token = getNextToken(parsedCommand.body, it++);
		if (pipeInfo.pipeId != 0) return "Komanda ne moze biti u pipe-u";
		if (parsedCommand.body.size() < 2) return "Premalo argumenata.";
		if (parsedCommand.body.size() > 2) return "Previse argumenata.";
		if (parsedCommand.redirection.hasInput || parsedCommand.redirection.hasAppend || parsedCommand.redirection.hasOutput) return "Komanda ne podrzava redirekcije.";
		if (!Command::isArgFile(token)) return "Nevalidan argument: " + token;
		
		return "valid";
	}

	else if (token == "tr") {
		token = getNextToken(parsedCommand.body, it++);
		if (parsedCommand.body.size() < 2) return "Premalo argumenata.";
		if (parsedCommand.body.size() > 4) return "Previse argumenata.";
		if ((Command::isArgText(token) || Command::isArgFile(token)) && parsedCommand.redirection.hasInput) return "Konflikt unosa i redirekcije.";
		if (Command::isArgFile(token)) {
			if (pipeInfo.pipeId != 0) return "Komanda u pipe-u ne moze imati unos.";
			parsedCommand.redirection.hasInput = true;
			ioInfo.input = streamManager.createIOStream(token);
		}
		else if (token[0] == '-' && token[1] == '"' && token[token.size() - 1] == '"') {
			token = getNextToken(parsedCommand.body, it++);
			if ((token != "" && Command::isArgText(token)) || token == "") return "valid";
			else return "Nevalidan argument: " + token;
		}
		
		token = getNextToken(parsedCommand.body, it++);
		if (token[0] == '-' && token[1] == '"' && token[token.size() - 1] == '"') {
			token = getNextToken(parsedCommand.body, it++);
			if ((token != "" && Command::isArgText(token)) || token == "") return "valid";
			else return "Nevalidan argument: " + token;
		}
		else return "Lose uneta opcija: " + token;

	}

	else return "Null";

}