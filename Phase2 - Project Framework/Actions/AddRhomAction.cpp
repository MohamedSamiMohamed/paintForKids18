#include "AddRhomAction.h"
#include "..\Figures\CRhombos.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRhomAction::AddRhomAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRhomAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rhombos: Click at centre");
	
	//Read centre and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	RhomGfxInfo.isFilled = UI.FigsFilled;	//default is not filled till one figure becomes filled
	//get drawing, filling colors and pen width from the interface
	RhomGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RhomGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRhomAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create a rhombus with the parameters read from the user
	CRhombos *R=new CRhombos(P1,RhomGfxInfo);

	//Add the rhombus to the list of figures
	pManager->AddFigure(R);
}
