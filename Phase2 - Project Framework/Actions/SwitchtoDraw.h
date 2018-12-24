#pragma once
#include"Action.h"


class SwitchtoDraw : public Action
{
public:
	SwitchtoDraw(ApplicationManager* pApp);

	void ReadActionParameters();

	void Execute();
	
};

