#include "ChangeFillColour.h"
#include"..\ApplicationManager.h"



ChangeFillColour::ChangeFillColour(ApplicationManager * pApp):Action(pApp)
{}

void ChangeFillColour::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CrntSelectedFig = pManager->Getselectedfigure();

	pOut->PrintMessage("Select a Colour from the colour pallete");
	newClr = pIn->GetUserAction();
}


void ChangeFillColour::Execute()
{
	Output* pOut = pManager->GetOutput();
	//Call read action parameters to get the selected figure and the required colour
	ReadActionParameters();

	//Check if there is no selected fig
	if (CrntSelectedFig == NULL)
	{
		pOut->PrintMessage("Error: No figure selected!");
	}
	else
	{
		//Switch to determine the required colour
		switch (newClr)
		{
		case RED_CLR:
			CrntSelectedFig->ChngFillClr(RED);
			UI.FillColor = RED;
			pOut->PrintMessage("Fill Colour Changed to Red");
			UI.FigsFilled = true;  //To make rest of figures filled with the ui current fill colour
			break;
		
		case BLACK_CLR:
			CrntSelectedFig->ChngFillClr(BLACK);
			UI.FillColor = BLACK;
			pOut->PrintMessage("Fill Colour Changed to Black");
			UI.FigsFilled = true;
			break;
		
		case GREEN_CLR:
			CrntSelectedFig->ChngFillClr(GREEN);
			UI.FillColor = GREEN;
			pOut->PrintMessage("Fill Colour Changed to Green");
			UI.FigsFilled = true;
			break;
		
		case BLUE_CLR:
			CrntSelectedFig->ChngFillClr(BLUE);
			UI.FillColor = BLUE;
			pOut->PrintMessage("Fill Colour Changed to Blue");
			UI.FigsFilled = true;
			break;
		
		case WHITE_CLR:
			CrntSelectedFig->ChngFillClr(WHITE);
			UI.FillColor = WHITE;
			pOut->PrintMessage("Fill Colour Changed to White");
			UI.FigsFilled = true;
			break;
		
		default:
			pOut->PrintMessage("Invalid Colour Selection");
		}
	}
}


