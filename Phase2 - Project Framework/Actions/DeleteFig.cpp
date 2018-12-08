#include "DeleteFig.h"
#include"../GUI/Output.h"
#include"../ApplicationManager.h"



DeleteFig::DeleteFig(ApplicationManager* pApp):Action(pApp)
{}

void DeleteFig::ReadActionParameters()
{
	//Get the selected figure to be deleted
	ToBeDeleted = pManager->Getselectedfigure();
}

void DeleteFig::Execute()
{
     Output* pOut = pManager->GetOutput();
	 ReadActionParameters();
	 
	 //No Selected Figure
	 if (ToBeDeleted == NULL)
	 {
		 pOut->PrintMessage("Error: No Figure Selected");
	 }
	 else
	 {
		 pOut->PrintMessage("Deleting Figure..");
		 pManager->DeleteFigure(ToBeDeleted);
	 }
}



