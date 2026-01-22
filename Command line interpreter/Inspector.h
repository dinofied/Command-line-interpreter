#pragma once
#include "Command.h"
#include "StreamManager.h"
class Inspector {
public:
	

	static bool isValidSyntax(ParsedCommand& parsedCommand, IOStreamInfo& ioInfo, PipeInfo pipeInfo);

	static string getNextToken(vector<string>& tokens, int tokenId);
	

};

