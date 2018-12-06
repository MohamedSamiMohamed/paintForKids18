#pragma once
#include "Action.h"

class SwitchToPlayMode:public Action
{
public:
	SwitchToPlayMode(ApplicationManager * pApp);
	~SwitchToPlayMode();
	void ReadActionParameters();
	void Execute();
};

