#include "Lexer.h"

vector<string> Lexer::divideWords(string inputLine) {
	vector<string> words;
	string word = "";

	for (int i = 0; i < inputLine.size(); i++) {

		if (inputLine[i] == '"') {
			if (word != "") {
				words.push_back(word);
				word = "";
			}
			findNextQuotationMark(i, word, inputLine);
			words.push_back(word);
			word = "";
		}
		if (i >= inputLine.size()) break;
		if (inputLine[i] == '>') {
			if (word != "") {
				words.push_back(word);
				word = "";
			}
			word += '>';
			if (i < inputLine.size() - 1) {
				i++;
				if (inputLine[i] == '>') {
					word += '>';
					words.push_back(word);
					word = "";
					continue;
				}
			}
			words.push_back(word);
			word = "";

		}

		if (inputLine[i] == '<') {
			if (word != "") {
				words.push_back(word);
				word = "";
			}
			words.push_back("<");
			continue;
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
	if (iterator < inputLine.size()) {
		word += inputLine[iterator];
		iterator++;
	}

}
