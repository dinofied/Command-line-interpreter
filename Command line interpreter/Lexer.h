#pragma once
#include <string>
#include <vector>
using namespace std;

class Lexer {
public:
	static Lexer& lexerInstance() {
		static Lexer instance;
		return instance;
	};

	vector<string> divideWords(string inputLine);
	void nextQuotation(int& num, string& word, string& inputLine);


private:
	Lexer() : charCount(0) {};
	int charCount;

};


