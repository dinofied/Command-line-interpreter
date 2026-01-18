#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Lexer {
public:
	static Lexer& lexerInstance() {
		static Lexer instance;
		return instance;
	};

	vector<string> divideWords(string inputLine);
	void findNextQuotationMark(int& num, string& word, string& inputLine);
	int getCharCount();


private:
	Lexer() : charCount(0) {};

protected:
	int charCount;

};


