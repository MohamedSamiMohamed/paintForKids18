#include "BringForward.h"
#include"..\ApplicationManager.h"



BringForward::BringForward(ApplicationManager* pApp):Action(pApp)
{}


void BringForward::ReadActionParameters()
{
	SelectedFig = pManager->Getselectedfigure();
}

void BringForward::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Gets the selected Figure
	ReadActionParameters();

	//Check if there is a figure selected
	if (!SelectedFig)
		pOut->PrintMessage("Error: NO FIGURE SELECTED!");
	else
	{
		pManager->SwapForward(SelectedFig);
	}
}

