#pragma once
#include <string>
#include <vector>
#include "Echo.h"
#include "Time.h"
#include "Date.h"
#include "Touch.h"
#include "wordCount.h"
#include "Prompt.h"
#include "Batch.h"
#include "Truncate.h"
#include "Rm.h"
#include "Head.h"
#include "Tr.h"
#include "Command.h"
#include "Inspector.h"

using namespace std;
class commandFactory {
public:

	static Command* createCmd(ParsedCommand parsedCommand, PipeInfo pipeInfo, StreamManager& streamManager, std::ostream& outputStream);

private:

	commandFactory() {};

};

