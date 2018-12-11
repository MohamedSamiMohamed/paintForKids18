#include "ApplicationManager.h"

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

			//M.A: case for change draw colour
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawClr(this);
			break;
		
			//M.A: case for changing the fill colour
		case CHNG_FILL_CLR:
			pAct = new ChangeFillColour(this);
			break;

			//M.A: case for delete figure
		case DEL:
			pAct = new DeleteFig(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case SAVE_BY_TYPE:
			pAct = new SaveByType(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;

		case TO_PLAY:
			pAct = new SwitchToPlayMode(this);
			break;

		case SELECT_BY_TYPE:
			pAct = new SelectByType(this);
			break;

		case SELECT_BY_COLOUR:
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


////////////////////////////////////////////////////////////////////////////////////////////
//                              Select Action Functions                                   //
////////////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::setselectedfig(CFigure* pFig)
{
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

////////////////////////////////////////////////////////////////////////////////////////////
//                              Save/Load Action Functions                                //
////////////////////////////////////////////////////////////////////////////////////////////


void ApplicationManager::SaveAll(ofstream &outFile) {

	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(outFile);
	}
}
void ApplicationManager::SaveByTypeFn(ofstream &outFile, ActionType A) {
	switch (A)
	{
	case DRAW_RECT: {
		CRectangle * rect;
		for (int i = 0; i < FigCount; i++)
		{
			rect = dynamic_cast<CRectangle *> (FigList[i]);
			if (rect != NULL) {
				FigList[i]->Save(outFile);
		}
		}
	}
		break;

	case DRAW_LINE: {
		CLine * line;
		for (int i = 0; i < FigCount; i++)
		{
			line = dynamic_cast<CLine *> (FigList[i]);
			if (line != NULL) {
				FigList[i]->Save(outFile);
			}
		}
	}
		break;

	case DRAW_RHOMBUS:
	{
		CRhombos * rho;
		for (int i = 0; i < FigCount; i++)
		{
			rho = dynamic_cast<CRhombos *> (FigList[i]);
			if (rho != NULL) {
				FigList[i]->Save(outFile);
			}
		}
	}
		break;

	case DRAW_ELLIPSE: {
		CEllipse * ell;
		for (int i = 0; i < FigCount; i++)
		{
			ell = dynamic_cast<CEllipse *> (FigList[i]);
			if (ell != NULL) {
				FigList[i]->Save(outFile);
			}
		}
	}
		break;

	case DRAW_TRI: {
		CTriangle * tri;
		
		for (int i = 0; i < FigCount; i++)
		{
			tri = dynamic_cast<CTriangle *> (FigList[i]);
			if (tri != NULL) {
				FigList[i]->Save(outFile);
			}
		}
	}
		break;

	default:
		break;
	}
}
void ApplicationManager::deleteAll() {
	for (int i = 0; i<FigCount; i++)
		delete FigList[i];
	FigCount = 0;
	pOut->ClearDrawArea();
}
bool ApplicationManager::isEmpty() {
	if (FigCount == 0) {
		return true;
	}
	return false;
}
bool  ApplicationManager::isFound(ActionType A) {
	switch (A)
	{
		case DRAW_RECT: {
			CRectangle * rect;
			for (int i = 0; i < FigCount; i++)
			{
				rect = dynamic_cast<CRectangle *> (FigList[i]);
				if (rect != NULL) {
					return true;
				}
			}
			return false;
		}
			break;

		case DRAW_LINE: {
			CLine * line;
			for (int i = 0; i < FigCount; i++)
			{
				line = dynamic_cast<CLine *> (FigList[i]);
				if (line != NULL) {
					return true;
				}
			}
			return false;
		}
			break;

		case DRAW_RHOMBUS:
		{
			CRhombos * rho;
			for (int i = 0; i < FigCount; i++)
			{
				rho = dynamic_cast<CRhombos *> (FigList[i]);
				if (rho != NULL) {
					return true;
				}
			}
			return false;
		}
			break;

		case DRAW_ELLIPSE: {
			CEllipse * ell;
			for (int i = 0; i < FigCount; i++)
			{
				ell = dynamic_cast<CEllipse *> (FigList[i]);
				if (ell != NULL) {
					return true;
				}
			}
			return false;
		}
			break;

	case DRAW_TRI: {
			CTriangle * tri;

			for (int i = 0; i < FigCount; i++)
			{
				tri = dynamic_cast<CTriangle *> (FigList[i]);
				if (tri != NULL) {
					return true;
				}
			}
			return false;
		}
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////
//                              Delete Action Functions                                   //
////////////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::DeleteFigure(CFigure* pFig)
{
	int i;
	for (i = 0; i < FigCount; i++)
	{
		//searching for the selected figure
		if (FigList[i] == pFig)
		{
			delete FigList[i];
			//Set selected figure to NULL
			SelectedFig = NULL;
			break;
		}

	}
	//Shift all pointers starting from i until the pointer before the last one 
	for (int j = i; j < FigCount - 1; j++)
	{
		FigList[j] = FigList[j + 1];
	}

	//Decrement the actual number of figures by one
	FigCount--;
	FigList[FigCount] = NULL;
	//Clear the draw area so that the deleted object disappears before updating interface
	pOut->ClearDrawArea();
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	deleteAll();
	delete pIn;
	delete pOut;

}

int ApplicationManager::countSpecificFigures(ActionType A) {
	int shapeCounter =0;
	switch (A)
	{
	case DRAW_RECT: {
		CRectangle * rect;
		for (int i = 0; i < FigCount; i++)
		{
			rect = dynamic_cast<CRectangle *> (FigList[i]);
			if (rect != NULL) {
				shapeCounter++;
			}
		}
	}
					break;

	case DRAW_LINE: {
		CLine * line;
		for (int i = 0; i < FigCount; i++)
		{
			line = dynamic_cast<CLine *> (FigList[i]);
			if (line != NULL) {
				shapeCounter++;
			}
		}
	}
					break;

	case DRAW_RHOMBUS:
	{
		CRhombos * rho;
		for (int i = 0; i < FigCount; i++)
		{
			rho = dynamic_cast<CRhombos *> (FigList[i]);
			if (rho != NULL) {
				shapeCounter++;
			}
		}
	}
	break;

	case DRAW_ELLIPSE: {
		CEllipse * ell;
		for (int i = 0; i < FigCount; i++)
		{
			ell = dynamic_cast<CEllipse *> (FigList[i]);
			if (ell != NULL) {
				shapeCounter++;
			}
		}
	}
					   break;

	case DRAW_TRI: {
		CTriangle * tri;

		for (int i = 0; i < FigCount; i++)
		{
			tri = dynamic_cast<CTriangle *> (FigList[i]);
			if (tri != NULL) {
				shapeCounter++;
			}
		}
	}
				   break;

	default:
		break;
	}
	return shapeCounter;
}