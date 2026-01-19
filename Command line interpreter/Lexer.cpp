#include "Lexer.h"

vector<string> Lexer::divideWords(string inputLine) {
	vector<string> words;
	string word = "";
	inputLine = inputLine.substr(0, 512);

	for (int i = 0; i < inputLine.size(); i++) {

		if (inputLine[i] == '"') {
			findNextQuotationMark(i, word, inputLine);
		}

		if (inputLine[i] != ' ' && inputLine[i] != '\t') word += inputLine[i];
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

void Lexer::findNextQuotationMark(int& iterator, string& word, string& inputLine) {

	word += inputLine[iterator];
	iterator++;
	while (iterator < inputLine.size() && inputLine[iterator] != '"') {
		word += inputLine[iterator];
		iterator++;
	}
};
