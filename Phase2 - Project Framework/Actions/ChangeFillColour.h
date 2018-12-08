#ifndef CHANGE_FILL_COLOUR_H
#define CHANGE_FILL_COLOUR_H

#include"Action.h"
#include"..\Figures\CFigure.h"


class ChangeFillColour:public Action
{
private:
	CFigure* CrntSelectedFig;
	ActionType newClr;

public:
	ChangeFillColour(ApplicationManager* pApp);
	
	//Reads if the currently selected figure and gets the required new colour
	virtual void ReadActionParameters();


	//Execute to change the fill colour of the selected figure
	virtual void Execute();

	
};
#endif 
