#ifndef ADD_RES_ACTION_H
#define ADD_RES_ACTION_H

#include "Action.h"

class ReSize : public Action
{
	private:
	Point P; 
	
public:
	ReSize(ApplicationManager *pApp);

	
	virtual void ReadActionParameters();
	
	
	virtual void Execute() ;

};

#endif