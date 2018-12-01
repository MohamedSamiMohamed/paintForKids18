#pragma once
#include"Actions/Action.h"
#include <fstream>
class SaveAction : public Action
{
public:
	SaveAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

