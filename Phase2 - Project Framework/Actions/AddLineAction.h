#ifndef ADD_LINE_ACTION_H
#define ADD_LINE_ACTION_H
#include "Action.h"

//Add Line Action class
class AddLineAction: public Action
{
private:
	Point P1, P2; //Line Endings
	GfxInfo lineGfxInfo;
public:
	AddLineAction(ApplicationManager *pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();
	
	//Add Line to the ApplicationManager
	virtual void Execute() ;
	
};

#endif