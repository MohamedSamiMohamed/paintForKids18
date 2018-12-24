#include "ByClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ByClr::ByClr(ApplicationManager * pApp):Action(pApp)
{}

void ByClr::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
}

//Execute the action
void ByClr::Execute() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->Play=1;
	int r;
	Input* pIn = pManager->GetInput();
	pManager->ExecuteAction(LOAD);
    pManager->UpdateInterface();
	int* ExistFig=pManager->ExistM();
	bool coloured=false;
	for(int i=0;i<6;i++)
  	  {
	 if(ExistFig[i]!=5 &&ExistFig[i]!=-1)
	   {
	 coloured=true;
  	 break;
       }
	  }
	 if(ExistFig==NULL)
	  {
	 pOut->PrintMessage("Make some Shapes First to plaay !!!! ");
  	 return;
	  }
	 if (coloured == false)
	  {
	 pOut->PrintMessage(" Colour Shapes First !!!  ");
	 return;
	  }
	 else
	  {
     r=pManager->TypeRandom(); 
	 pOut->PrintMessage("Please Wait !!!! ");
	 pManager->playMessage(r);
	 int Count =pManager->NumCertainShapes(r);
	 CFigure* playFigure=NULL;
	 int Correct =0 ;
	 int NonCorrect =0;
	 while(Count !=0) 
	{	
	  pIn->GetPointClicked(P.x, P.y);
	    if ( P.y >= 0 && P.y < UI.ToolBarHeight)
	     {	
		int ClickedItemOrder = (P.x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		  {
		 case ITM_FIGTYPE: 
		   pManager->Replay=true;
		   pManager->ExecuteAction(SELECT_BY_TYPE);
		   return;
		 case ITM_FIGCOL: 
		   pManager->Replay=true;
		   pManager->ExecuteAction(SELECT_BY_COLOUR);
		   return;
		 case ITM_DRAW:
		   pManager->ExecuteAction(TO_DRAW);
           return;
		 case ITM_EXIT2: return;
		 default: return ;	//A click on empty place in desgin toolbar
			}
		
		}
		playFigure=pManager->GetFigure(P.x, P.y);
		  if (playFigure!=NULL)
		   {
		  pManager->play( playFigure , r, Count, Correct, NonCorrect);
		   }
	    pManager->UpdateInterface();
	    playFigure=NULL;
	 }
 	pOut->PrintMessage("Game Over ! Your Score ... Correct Picks : "  + to_string(Correct) + " , NonCorrect Picks : " + to_string(NonCorrect));
	pManager->Replay=false;
	}
}