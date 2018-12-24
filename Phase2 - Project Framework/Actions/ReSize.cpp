#include"ReSize.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


ReSize::ReSize(ApplicationManager * pApp):Action(pApp)
{}

void ReSize::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select the figure you want");
	
	//Read center and store in point P1
	pIn->GetPointClicked(P.x, P.y);
    pOut->ClearStatusBar();

}

//Execute the action
void ReSize::Execute() 
{
	//This action needs to read some parameters first
	
	ReadActionParameters();
	CFigure* Figure=pManager->GetFigure(P.x, P.y);
	if(Figure != NULL)
	{
		
		pManager->DeleteFigure(Figure);
	}
	
	
	
}










