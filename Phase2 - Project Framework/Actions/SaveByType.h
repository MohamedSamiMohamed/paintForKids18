#pragma once
#include "Action.h"
#include <fstream>
class SaveByType : public Action
{
private:
	string inputString;
	ActionType ActType;
public:
	SaveByType(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

