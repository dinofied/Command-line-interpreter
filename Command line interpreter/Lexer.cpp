#include "Lexer.h"

vector<string> Lexer::divideWords(string inputLine) {
	vector<string> words;
	string word = "";
	inputLine = inputLine.substr(0, 512);

	for (int i = 0; i < inputLine.size(); i++) {
		charCount++;

		if (inputLine[i] == '"') {
			nextQuotation(i, word, inputLine);
		}

		if (inputLine[i] != ' ') word += inputLine[i];
		else {
			if (word != "") {
				words.push_back(word);
				word = "";
			}
		}
	}
	if (word != "") words.push_back(word);
	return words;
}

void Lexer::nextQuotation(int& iterator, string& word, string& inputLine) {

	word += inputLine[iterator];
	iterator++;
	while (iterator < inputLine.size() && inputLine[iterator] != '"') {
		charCount++;
		word += inputLine[iterator];
		iterator++;
	}
	charCount++;
};