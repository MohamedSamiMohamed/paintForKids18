#pragma once
#include"Action.h"
#include"..\Figures\CFigure.h"

class BringForward : public Action
{
private:
	CFigure* SelectedFig;
public:
	BringForward(ApplicationManager* pApp);
	
	//Reads the selected figure
	void ReadActionParameters();

	//Brings the figure forward one step
	void Execute();

};

