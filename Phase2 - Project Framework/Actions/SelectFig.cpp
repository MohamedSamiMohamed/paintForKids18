#include "SelectFig.h"

#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



SelectFig::SelectFig(ApplicationManager* pApp):Action(pApp)
{}


void SelectFig::ReadActionParameters()
{
	//Get a pointe for the input and output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Get a point chosen to select/unselect the figure
	pOut->PrintMessage("Select/Unselect Figure: Select a Figure ");
	pIn->GetPointClicked(P.x, P.y);

	pOut->ClearStatusBar();
}

void SelectFig::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();

	//Call ApplicationManager :: Getfigure() to determine where i clicked
	CFigure* ToBeSelected = pManager->GetFigure(P.x, P.y);

	//case1 : No figures selected and i want to select a figure

	//If no figure is selected:
	if (pManager->Getselectedfigure() == NULL)
	{
		//A figure is to be selected
		if (ToBeSelected != NULL)
		{
			//Set figure to be selected
			ToBeSelected->SetSelected(true);
			//set a currently selected figure for the program
			pManager->setselectedfig(ToBeSelected);
			//print the information of the selected figure
			ToBeSelected->PrintInfo(pOut);
		}
	}

	//If a figure was selected
	else if (pManager->Getselectedfigure() != NULL)
	{
		//case2: deselecting a selected figure without selecting another(Re-clicking) or deselecting and selecting another
		if (ToBeSelected != NULL)
		{
			if (ToBeSelected->IsSelected())
			{
				//Deselect the figure
				ToBeSelected->SetSelected(false);
				//No figure becomes selected
				pManager->SetSelectedfigNULL();

			}
			//case : Selecting another shape and deslecting the selected one
			else
			{
				//Deslecting the currently selected
				CFigure* tempfig = pManager->Getselectedfigure();
				tempfig->SetSelected(false);
				pManager->SetSelectedfigNULL();

				//selecting the new figure
				ToBeSelected->SetSelected(true);
				pManager->setselectedfig(ToBeSelected);
				ToBeSelected->PrintInfo(pOut);
			}
		}
		//case3: a figure is selected and we click on  an empty area
		else if (ToBeSelected == NULL)
		{
			CFigure* tempfig = pManager->Getselectedfigure();
			tempfig->SetSelected(false);
			pManager->SetSelectedfigNULL();
		}
	}
	
}