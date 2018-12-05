#ifndef ADD_RHOM_ACTION_H
#define ADD_RHOM_ACTION_H
#include "Action.h"

//Add Rhombos Action class
class AddRhomAction: public Action
{
private:
	Point P1; //Rhom centre
	GfxInfo RhomGfxInfo;
public:
	AddRhomAction(ApplicationManager *pApp);

	//Reads Rhombos parameters
	virtual void ReadActionParameters();
	
	//Add Rhombos to the ApplicationManager
	virtual void Execute() ;
	
};

#endif