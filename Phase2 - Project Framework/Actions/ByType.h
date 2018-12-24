#ifndef BY_TYPE_ACTION_H
#define BY_TYPE_ACTION_H

#include "Action.h"

class ByType: public Action
{
private:
	Point P;


public:
	
	ByType(ApplicationManager *pApp);

	virtual void ReadActionParameters();
	
	virtual void Execute() ;
	
};

#endif