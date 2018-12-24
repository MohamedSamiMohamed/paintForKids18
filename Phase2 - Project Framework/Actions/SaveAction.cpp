#include "SaveAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>

SaveAction::SaveAction(ApplicationManager * pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("please enter the file name to be saved");
	inputString = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
}
void SaveAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->isEmpty()) {
		pOut->PrintMessage("no shape to save!");
	}
	else {
		ReadActionParameters();
		ofstream myfile;
		inputString =inputString + ".txt";
		myfile.open(inputString);
		pManager->SaveAll(myfile);
		myfile.close();
	}
}


