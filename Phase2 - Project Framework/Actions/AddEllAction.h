#ifndef ADD_ELL_ACTION_H
#define ADD_ELL_ACTION_H

#include "Action.h"

class AddEllAction : public Action
{
	private:
	Point P1; //Ellipse center
	GfxInfo EllGfxInfo;
public:
	AddEllAction(ApplicationManager *pApp);

	//Reads ellipse parameters
	virtual void ReadActionParameters();
	
	//Add ellipse to the ApplicationManager
	virtual void Execute() ;

};

#endif