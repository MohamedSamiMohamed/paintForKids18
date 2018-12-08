#ifndef DELETE_FIG_H
#define DELETE_FIG_H

#include"Action.h"
#include"..\Figures\CFigure.h"

class DeleteFig : public Action 
{
private:
	CFigure* ToBeDeleted;
public:
	DeleteFig(ApplicationManager* pApp);
	
	//Gets the Selected Figure to be deleted 
	virtual void ReadActionParameters();

	//Execute the delete action by calling a function from the application manager
	virtual void Execute();

};
#endif 

