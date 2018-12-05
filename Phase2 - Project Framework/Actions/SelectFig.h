#ifndef SELECT_FIG_H
#define SELECT_FIG_H

#include"Action.h"

class SelectFig : public Action
{
private:
	Point P;
public:
	SelectFig(ApplicationManager* pApp);
	
	//Reads the users click
	virtual void ReadActionParameters();

	//Selects\unselects the figure
	virtual void Execute();
};

#endif
