#include "SwitchToPlayMode.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager * pApp) :Action(pApp)
{}

SwitchToPlayMode::~SwitchToPlayMode()
{
}
void SwitchToPlayMode::ReadActionParameters() {
	//empty
}

void SwitchToPlayMode::Execute() {
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	ofstream myfile;
	myfile.open("temp.txt");
	pManager->SaveAll(myfile);
	myfile.close();
	//Get a Pointer to the Input / Output Interfaces
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
