#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddEllAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\AddTriAction.h"

#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"

#include "Actions\SelectFig.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	
	SelectedFig = NULL; //M.A : The program should start with no selected figures
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_ELLIPSE:
			pAct = new AddEllAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_RHOMBUS:
			pAct = new AddRhomAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

        //M.A : Added case to create SelectFig Object
		case SELECT:
			pAct = new SelectFig(this);
			break;
		
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;

		case EXIT:
			///create ExitAction here
			
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount)
	{
		//M.A : Add the id to the figure before adding
		pFig->SetFigID(FigCount);

		FigList[FigCount++] = pFig;
	}
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL


	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	bool figfound = false;
	for (int i = FigCount - 1; i >= 0; i--)
	{
		figfound = FigList[i]->Isinsideboundaries(x, y);
		//if x and y are inside the boundaries of that figure i
		if (figfound)
		{
			return FigList[i];
		}
	}

    return NULL;
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }


void ApplicationManager::setselectedfig(CFigure* pFig)
{
	//M.A : Still not sure ! Do we need dynamic allocation for selected fig 
	//M.A : Fig can be changed from outside so i point to a an object that was already created
	SelectedFig = pFig;  
}

CFigure* ApplicationManager::Getselectedfigure() const
{
	//Returns the current selected figure
	return SelectedFig;
}

void ApplicationManager::SetSelectedfigNULL()
{
	SelectedFig = NULL;
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
void ApplicationManager::SaveAll(ofstream &outFile) {

	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(outFile);
	}
}