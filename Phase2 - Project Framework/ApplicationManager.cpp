#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddEllAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddRhomAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include "Actions/SaveByType.h"
#include "Actions/SwitchToPlayMode.h"
#include "Actions\ByType.h"
#include "Actions\ByClr.h"

#include "Actions/SelectFig.h"
#include"Actions/ChangeDrawClr.h"
#include"Actions/ChangeFillColour.h"
#include"Actions/DeleteFig.h"
#include "Actions/ReSize.h"
#include"Actions/SwitchtoDraw.h"
#include"Actions/SendToBack.h"
#include"Actions/BringForward.h"


#include "Figures/CRectangle.h"
#include "Figures/CEllipse.h"
#include "Figures/CLine.h"
#include "Figures/CRhombos.h"
#include "Figures/CTriangle.h"
#include <stdlib.h>
#include <time.h>

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	Replay=false;
	
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

			//M.A: case for sending backwards
		case SEND_TO_BACK:
			pAct = new SendToBack(this);
			break;

			//M.A: Case for Bringing Forward
		case BRING_TO_FRONT:
			pAct = new BringForward(this);
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

		case TO_DRAW:
			pAct = new SwitchtoDraw(this);
			break;


		case SELECT_BY_TYPE :
			pAct= new ByType(this);
			break;

	    case SELECT_BY_COLOUR :
			pAct= new ByClr(this);
			break;
		case RESIZE :
			pAct= new ReSize(this);
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
		//M.A: to prevent drawing in  an invalid area by preventing the add of the figure to the figure list
		if (pFig->Isinvalid())
		{
			pOut->PrintMessage("Error : Invalid location to add the Figure!");
		}
		else
		{
			FigList[FigCount++] = pFig;
		}
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

////////////////////////////////////////////////////////////////////////////////////////////
//                              Play Mode Action Functions                                //
////////////////////////////////////////////////////////////////////////////////////////////

int ApplicationManager::TypeRandom()
{
	while(true)
	{
	srand(time(NULL) );
	int r =rand()%6;
	   for(int i=0;i<6;i++)
	    {
	   if( r==ExistNum[i])
	   return r;
	    }
	}

}
int* ApplicationManager::ExistM()
{
	if(FigList[0]==NULL)
		return NULL;
	if(Play==0)
	{
	 for(int j=0;j<6;j++)
	   {
	 ExistNum[j]=-1;
	   }
	 for(int j=0;j<5;j++)
	    for(int i=0; i<FigCount; i++)
	      {
		 switch(j)
		   {
		 case 0 :
			CEllipse * ell;
			ell = dynamic_cast<CEllipse *> (FigList[i]);
			if (ell != NULL )
			{
			ExistNum [j]=0;
			}
			break;
	     case 1 :
			CLine * line;
			line = dynamic_cast<CLine *> (FigList[i]);
			if (line != NULL )
			{
			ExistNum [j]=1;
			}
			break;
		 case 2 :
			CRectangle * rect;
			rect = dynamic_cast<CRectangle *> (FigList[i]);
			if (rect != NULL )
			{
			ExistNum [j]=2;
			}
			break;
	      case 3 :
			CRhombos * rhom;
			rhom = dynamic_cast<CRhombos *> (FigList[i]);
			if (rhom != NULL )
			{
			ExistNum [j]=3;
			}
			break;
		  case 4 :
			CTriangle * tri;
			tri = dynamic_cast<CTriangle *> (FigList[i]);
			if (tri != NULL )
			{
			ExistNum [j]=4;
			}
			break;
			
		   }
	     }
	   }
   else
	{
	 for(int j=0;j<6;j++)
	   {
	 ExistNum[j]=-1;
	    }
	 for(int j=0;j<6;j++)
	       for(int i=0; i<FigCount; i++)
	        {
	      switch(j)
		     {
	      case 0 : 
			if (FigList[i]->FigGfxInfo.FillClr==RED )
			{
			ExistNum [j]=0;
			}
			break;
	      case 1 : 
			if (FigList[i]->FigGfxInfo.FillClr==WHITE)
			{
			ExistNum [j]=1;
			}
			break;
		  case 2 : 
			if (FigList[i]->FigGfxInfo.FillClr==BLACK )
			{
			ExistNum [j]=2;
			}
			break;
		  case 3 : 
		    if (FigList[i]->FigGfxInfo.FillClr==GREEN && FigList[i]->FigGfxInfo.isFilled==true)
			{
			ExistNum [j]=3;
			}
			break;
		  case 4 :
			if (FigList[i]->FigGfxInfo.FillClr==BLUE )
			{
			ExistNum [j]=4;
			}
			break;
	      case 5 : 
		    if (FigList[i]->FigGfxInfo.isFilled==false)
			{
			ExistNum [j]=5;
			}
			break;
			
	      	}
		  }
	}
	return ExistNum;
}

void ApplicationManager::playMessage(int r)
{
	if(Play==0)
	 {
      switch (r)
         { 
        case 0 :
		 pOut->PrintMessage("Pick up all Ellipses !!!! ");
	     break;
	    case 1 :
		 pOut->PrintMessage("Pick up all Lines !!!! ");
		 break;
		case 2 : 
		 pOut->PrintMessage("Pick up all Rectangles !!!! ");
	  	 break;
		case 3 :
		 pOut->PrintMessage("Pick up all Rhomboses!!!! ");
   		 break;
		case 4 :
		 pOut->PrintMessage("Pick up all Triangles !!!! ");
		 break;
         }
	
      }
	else
	  {
     switch (r)
        {
	   case 0 :
		pOut->PrintMessage("Pick up all RED SHAPES !!!! ");
	    break;
	   case 1 :
		pOut->PrintMessage("Pick up all WHITE SHAPES !!!! ");
		break;
	   case 2 : 
		pOut->PrintMessage("Pick up all BLACK SHAPES !!!! ");
		break;
	   case 3 :
		pOut->PrintMessage("Pick up all GREEN SHAPES!!!! ");
	    break;
	   case 4 :
		pOut->PrintMessage("Pick up all BLUE SHAPES !!!! ");
		break;
	   case 5 :
		pOut->PrintMessage("Pick up all UNCOLOURED SHAPES !!!! ");
		break;
	     }
	   }
  }
void ApplicationManager::play(CFigure*& playFigure,int r,int& Count,int& Correct,int& NonCorrect)
{
  if(Play==0)
	 {
	switch(r)
	  {
	 case 0:
	   CEllipse * ell;
	   ell = dynamic_cast<CEllipse *> (playFigure);
	   if (ell != NULL)
		 {
	   Correct ++;
	   Count--;
	   DeleteFigure(playFigure);
	   break;
		 }
	   DeleteFigure(playFigure);
	   NonCorrect++;
       break;
	  case 1:
	   CLine * line;
	   line = dynamic_cast<CLine *> (playFigure);
	   if (line != NULL  )
		 {
	   Correct ++;
	   Count--;
       DeleteFigure(playFigure);
	   break;
		 }
	   DeleteFigure(playFigure);
	   NonCorrect++;
       break;
	  case 2:
	   CRectangle * rect;
	   rect = dynamic_cast<CRectangle *> (playFigure);
	   if (rect != NULL)
		 {
	   Correct ++;
	   Count--;
	   DeleteFigure(playFigure);
	   break;
     	 }
	   DeleteFigure(playFigure);
	   NonCorrect++;
       break;
	  case 3:
	   CRhombos * rhom;
	   rhom = dynamic_cast<CRhombos *> (playFigure);
	   if (rhom != NULL)
		 {
	   Correct ++;
	   Count--;
	   DeleteFigure(playFigure);
	   break;
		 }
	   DeleteFigure(playFigure);
	   NonCorrect++;
       break;
	  case 4:
	   CTriangle * tri;
	   tri = dynamic_cast<CTriangle *> (playFigure);
	   if (tri != NULL)
		 {
	   Correct ++;
	   Count--;
	   DeleteFigure(playFigure);
	   break;
		 }
	   DeleteFigure(playFigure);
	   NonCorrect++;
       break;
	  }
	}
    else
	   {
	switch(r)
	   {
	 case 0 : 
		if (playFigure->FigGfxInfo.FillClr==RED )
			{
		Correct ++;
	    Count--;
		DeleteFigure(playFigure);
		break;
			}
		DeleteFigure(playFigure);
	    NonCorrect++;
        break;
      case 1 : 
		if (playFigure->FigGfxInfo.FillClr==WHITE)
			{
		Correct ++;
	    Count--;
		DeleteFigure(playFigure);
		break;
			}
		DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	  case 2 : 
		if (playFigure->FigGfxInfo.FillClr==BLACK )
			{
		Correct ++;
	    Count--;
		DeleteFigure(playFigure);
		break;
			}
		DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	  case 3 : 
	    if (playFigure->FigGfxInfo.FillClr==GREEN && playFigure->FigGfxInfo.isFilled==true)
			{
		Correct ++;
	    Count--;
		DeleteFigure(playFigure);
		break;
			}
		DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	  case 4 :
		if (playFigure->FigGfxInfo.FillClr==BLUE )
			{
		Correct ++;
	    Count--;
		DeleteFigure(playFigure);
		break;
			}
		DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	   case 5 : 
	    if (playFigure->FigGfxInfo.isFilled==false)
			{
		Correct ++;
	    Count--;
		DeleteFigure(playFigure);
		break;
			}
		DeleteFigure(playFigure);
	    NonCorrect++;
        break;
		  }
	    }
  }

int ApplicationManager:: NumCertainShapes(int r)
{
  int Count=0;
	if (Play==0)
	  {
	for(int i=0; i<FigCount; i++)
	   {
	  switch(r)
		{
		 case 2 :
			CRectangle * rect;
			rect = dynamic_cast<CRectangle *> (FigList[i]);
			if (rect != NULL )
			  {
			Count++;
			  }
			break;
		 case 0 :
			CEllipse * ell;
			ell = dynamic_cast<CEllipse *> (FigList[i]);
			if (ell != NULL )
			  {
			Count++;
			  }
			break;
	     case 1 :
			CLine * line;
			line = dynamic_cast<CLine *> (FigList[i]);
			if (line != NULL )
			  {
			Count++;
			  }
			break;
		 case 3 :
			CRhombos * rhom;
			rhom = dynamic_cast<CRhombos *> (FigList[i]);
			if (rhom != NULL )
			  {
			Count++;
			  }
			break;
		 case 4 :
			CTriangle * tri;
			tri = dynamic_cast<CTriangle *> (FigList[i]);
			if (tri != NULL )
			  {
			Count++;
			  }
			break;
		}
	  }
	}
	 else
	   {
      for(int i=0; i<FigCount; i++)
	    {
	   switch(r)
		{
	    case 0 : 
		 if (FigList[i]->FigGfxInfo.FillClr==RED )
			{
		 Count++;
			}
		 break;
	    case 1 : 
		 if (FigList[i]->FigGfxInfo.FillClr==WHITE)
		    {
		 Count++;
			}
		 break;
		case 2 : 
		 if (FigList[i]->FigGfxInfo.FillClr==BLACK )
			{
		 Count++;
		    }
		 break;
		case 3 : 
		 if (FigList[i]->FigGfxInfo.FillClr==GREEN && FigList[i]->FigGfxInfo.isFilled==true)
			{
		 Count++;
			}
		 break;
		case 4 :
		 if (FigList[i]->FigGfxInfo.FillClr==BLUE )
			{
		 Count++;
			}
		 break;
	    case 5 : 
		 if (FigList[i]->FigGfxInfo.isFilled==false)
			{
	     Count++;
		    }
		 break;
		  }
		}
	}
  return Count ;
}

////////////////////////////////////////////////////////////////////////////////////////////
//                              Swaping Functions                                         //
////////////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::SwapBackward(CFigure* pFig)
{
	//Temporary pointer for swaping
	CFigure* temp;

	//if it is the first Figure
	if (pFig == FigList[0])
	{
		pOut->PrintMessage("CAN'T SEND BACKWARD!");
		return;
	}
	//Starting from the second Figure in the figlist
	for (int i = 1; i < FigCount; i++)
	{
		//Searching for figure by comparing addresses
		if (FigList[i] == pFig)
		{
			temp = FigList[i];
			//Shift all figures till the selected figure
			for (int j = i; j > 0; j--)
			{
				FigList[j] = FigList[j - 1];
			}
			//Put the selected pointer first one in  the array
			FigList[0] = temp;

			pOut->PrintMessage("Sending to Back..");
			break;
		}
	}
}

void ApplicationManager::SwapForward(CFigure* pFig)
{
	//Temporary pointer for swaping
	CFigure* temp;

	//if it is the last Figure
	if (pFig == FigList[FigCount - 1])
	{
		pOut->PrintMessage("CAN'T SEND FORWARD!");
		return;
	}
	//Starting from the second Figure in the figlist
	for (int i = 0; i < FigCount - 1; i++)
	{
		//Searching for figure by comparing addresses
		if (FigList[i] == pFig)
		{
			temp = FigList[i];
			//Shifting all figures
			for (int j = i; j < FigCount - 1; j++)
			{
				FigList[j] = FigList[j + 1];
			}

			FigList[FigCount - 1] = temp;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	deleteAll();
	delete pIn;
	delete pOut;

}

