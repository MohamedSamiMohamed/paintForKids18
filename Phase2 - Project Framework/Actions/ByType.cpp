#include "..\Actions\ByType.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

ByType::ByType(ApplicationManager * pApp):Action(pApp)
{}

void ByType::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
}

//Execute the action
void ByType::Execute() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->Play=0; //To get the output of application manager as pick by type mode
	int r; // random	
	Input* pIn = pManager->GetInput();
    pManager->ExecuteAction(LOAD);  ////// restart  //////////////
    pManager->UpdateInterface();   ////// the game /////////////
	int* ExistFig=pManager->ExistM(); // determine exist shapes or coloures
	if(ExistFig==NULL)
	  {
    pOut->PrintMessage("Make some Shapes First to plaay !!!! ");
	  }
	else
	  {
	r=pManager->TypeRandom(); // select randomly from existing shapes or coloures 
    pOut->PrintMessage("Please Wait !!!! ");
	pManager->playMessage(r); // tell user which shape/colour to pick
	int Count =pManager->NumCertainShapes(r); // determine number of shapes should be picked to win
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
		 case ITM_EXIT2:
		   return;
		 default:
		   return;	//A click on empty place in desgin toolbar
			}
		  }
	   playFigure=pManager->GetFigure(P.x, P.y);
	   if (playFigure!=NULL)
		 {
	   pManager->play( playFigure , r, Count, Correct, NonCorrect); // play function
		 }
	   pManager->UpdateInterface();
	   playFigure=NULL;
       	}
	pOut->PrintMessage("Game Over ! Your Score ... Correct Picks : "  + to_string(Correct) + " , NonCorrect Picks : " + to_string(NonCorrect));
	pManager->Replay=false;
        	} 
}