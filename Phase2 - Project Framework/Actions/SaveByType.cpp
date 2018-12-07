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

	pOut->PrintMessage("please enter the file name to be saved");
	inputString = pIn->GetSrting(pOut);

	pOut->PrintMessage("please choose the figure to be saved");
	ActType = pIn->GetUserAction();
}

void SaveByType::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();
	if (ActType != 0 && ActType != 1 && ActType != 2 && ActType != 3 && ActType != 4)
	{
		pOut->PrintMessage("Invalid");
	}
	else if (!(pManager->isFound(ActType))) {	//no shapes of that type
		string shape;
		switch (ActType) {
			case 0:
				shape = "lines";
				break;
			case 1:
				shape = "rectangles";
				break;
			case 2:
				shape = "triangles";
				break;
			case 3:
				shape = "rhomboses";
				break;
			case 4:
				shape = "ellipses";
				break;
		}
		pOut->PrintMessage("no " + shape + " are found");
	}
	else {
		pOut->PrintMessage("saved");
		ofstream myfile;
		inputString = inputString + ".txt";
		myfile.open(inputString);
		pManager->SaveByTypeFn(myfile, ActType);
		myfile.close();
	}
}
