#pragma once
#include "Action.h"
#include <fstream>
class SaveAction : public Action
{
private:
	string inputString;
public:
	SaveAction(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
};

