#pragma once
#include <string>


class readySign {
public:

	static readySign& signInstance() {
		static readySign instance;
		return instance;
	};

	void setReadySign(std::string sign);
	std::string getReadySign();




private:
	std::string sign;

	readySign() : sign("&") {};


};

