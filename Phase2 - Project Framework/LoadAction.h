#pragma once
#include "Actions/Action.h"
#include <fstream>

class LoadAction:public Action
{
	string inputString;
public:
	LoadAction(ApplicationManager * pApp);
	void LoadAction::ReadActionParameters();
	void LoadAction::Execute();
};

