#pragma once
#include "Action.h"
#include <fstream>

class LoadAction:public Action
{
	string inputString;
public:
	LoadAction(ApplicationManager * pApp);
	void ReadActionParameters();
	void Execute();
};

