#ifndef CHANGE_DRAW_CLR_H
#define CHANGE_DRAW_CLR_H

#include"Action.h"
#include"..\Figures\CFigure.h"

class ChangeDrawClr : public Action
{
private:
	CFigure* CrntSelectedFig;
	ActionType newClr;

public:
	ChangeDrawClr(ApplicationManager * pApp);

	//Reads the currently selected figure and gets the required new colour
	virtual void ReadActionParameters();

	//Executes the action to change the draw color
	virtual void Execute();
	
		
};
#endif
