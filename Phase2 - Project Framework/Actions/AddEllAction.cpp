#include"AddEllAction.h"
#include "..\Figures\CEllipse.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddEllAction::AddEllAction(ApplicationManager * pApp):Action(pApp)
{}

void AddEllAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Ellipse: Click at center");
	
	//Read center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	EllGfxInfo.isFilled = false;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	EllGfxInfo.DrawClr = pOut->getCrntDrawColor();
	EllGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddEllAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();
	
	//Create an Ellipse with the parameters read from the user
	CEllipse *R=new CEllipse(P1, EllGfxInfo);

	//Add the Ellipse to the list of figures
	pManager->AddFigure(R);
}










