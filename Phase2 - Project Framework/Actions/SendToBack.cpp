#include "SendToBack.h"
#include"..\ApplicationManager.h"



SendToBack::SendToBack(ApplicationManager* pApp):Action(pApp)
{}

void SendToBack::ReadActionParameters()
{
	SelectedFig = pManager->Getselectedfigure();
}

void SendToBack::Execute()
{
	Output* pOut = pManager->GetOutput();

	//Gets the selected Figure
	ReadActionParameters();

	//Check if there is a figure selected
	if (!SelectedFig)
		pOut->PrintMessage("Error: NO FIGURE SELECTED!");
	else
	{
		pManager->SwapBackward(SelectedFig);
		
	}
}


