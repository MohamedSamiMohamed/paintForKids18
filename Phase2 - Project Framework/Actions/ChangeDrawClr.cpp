#include "ChangeDrawClr.h"
#include"..\ApplicationManager.h"



ChangeDrawClr::ChangeDrawClr(ApplicationManager* pApp):Action(pApp)
{}

void ChangeDrawClr::ReadActionParameters()
{
	Output * pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();

	pOut->PrintMessage("Select a Colour from the Colour Pallete");
	newClr = pIn->GetUserAction();
	CrntSelectedFig = pManager->Getselectedfigure();
}

void ChangeDrawClr::Execute()
{
	Output * pOut = pManager->GetOutput();
	
	//Gets the curently selected figure
	ReadActionParameters();

	//Check if there is a selected figure
	if (CrntSelectedFig == NULL)
	{
		pOut->PrintMessage("Error : NoFigure Selected");
	}
	else
	{
		switch (newClr)
		{
		case RED_CLR:
			UI.DrawColor = RED;
			CrntSelectedFig->ChngDrawClr(RED);
			pOut->PrintMessage("Drawing colour changed to RED");
			break;
		case BLACK_CLR:
			UI.DrawColor = BLACK;
			CrntSelectedFig->ChngDrawClr(BLACK);
			pOut->PrintMessage("Drawing colour changed to BLACK");
			break;
		case GREEN_CLR:
			UI.DrawColor = GREEN;
			CrntSelectedFig->ChngDrawClr(GREEN);
			pOut->PrintMessage("Drawing colour changed to GREEN");
			break;
		case BLUE_CLR:
			UI.DrawColor = BLUE;
			CrntSelectedFig->ChngDrawClr(BLUE);
			pOut->PrintMessage("Drawing colour changed to BLUE");
			break;
		case WHITE_CLR:
			UI.DrawColor = WHITE;
			CrntSelectedFig->ChngDrawClr(WHITE);
			pOut->PrintMessage("Drawing colour changed to WHITE");
			break;
		default:
			pOut->PrintMessage("Invalid Colour Selection!");

		}
	}
}


