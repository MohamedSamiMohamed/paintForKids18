#pragma once
#include "Action.h"
class SelectByType :
	public Action
{
public:
	SelectByType(ApplicationManager * pApp);
	~SelectByType();
	void ReadActionParameters();
	void Execute();
};

