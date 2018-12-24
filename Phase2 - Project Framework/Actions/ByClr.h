#ifndef BY_CLR_ACTION_H
#define BY_CLR_ACTION_H

#include "Action.h"

class ByClr: public Action
{
private:
	Point P;


public:
	
	ByClr(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

#endif