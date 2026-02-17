#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Lexer {
public:

	static vector<string> divideWords(string inputLine);
	static void findNextQuotationMark(int& num, string& word, string& inputLine);


private:

	Lexer() {};
};


