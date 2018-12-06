#include "SaveByType.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>

SaveByType::SaveByType(ApplicationManager * pApp) :Action(pApp)
{}

void SaveByType::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("please choose the figure");
	ActType = pIn->GetUserAction();

	pOut->PrintMessage("please enter the file name");
	inputString = pIn->GetSrting(pOut);
}

void SaveByType::Execute()
{
	ReadActionParameters();
	ofstream myfile;
	inputString = inputString + ".txt";
	myfile.open(inputString);
	pManager->SaveByTypeFn(myfile,ActType);
	myfile.close();
}
