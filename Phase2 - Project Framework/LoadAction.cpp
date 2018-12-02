#include "LoadAction.h"
#include "Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI\Output.h"
#include <iostream>


LoadAction::LoadAction(ApplicationManager * pApp) :Action(pApp)
{}
void LoadAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	inputString = pIn->GetSrting(pOut);

}
void LoadAction::Execute() {
	ReadActionParameters();
	inputString = inputString + ".txt";
	ifstream myfile(inputString); //opens the file
	if (myfile.is_open())
	{
		pManager->LoadAll(myfile);
		myfile.close();
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		pOut->PrintMessage("Unable to open file");
	}

}
