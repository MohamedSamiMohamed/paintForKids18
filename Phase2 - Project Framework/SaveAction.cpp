#include "SaveAction.h"
#include "Figures\CRectangle.h"

#include "ApplicationManager.h"

#include "GUI/Input.h"
#include "GUI\Output.h"
#include <iostream>
SaveAction::SaveAction(ApplicationManager * pApp) :Action(pApp)
{}
void SaveAction::ReadActionParameters() {

}
void SaveAction::Execute() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string inputString = pIn->GetSrting(pOut); 
	ofstream myfile;
	inputString = inputString + ".txt";
	myfile.open(inputString);
	pManager->SaveAll(myfile);
	myfile.close();
}


