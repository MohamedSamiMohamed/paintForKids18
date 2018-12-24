#pragma once
#include"Action.h"
#include"..\Figures\CFigure.h"

class SendToBack : public Action
{
private:
	CFigure* SelectedFig;
	

public:
	SendToBack(ApplicationManager* pApp);
	
	//Reads the selected figure
	void ReadActionParameters();

	//Sends the figure Backward one step
	void Execute();

};

