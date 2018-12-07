#include "SwitchToPlayMode.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager * pApp) :Action(pApp)
{}

SwitchToPlayMode::~SwitchToPlayMode()
{
}
void SwitchToPlayMode::ReadActionParameters() {
	//empty
}

void SwitchToPlayMode::Execute() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
