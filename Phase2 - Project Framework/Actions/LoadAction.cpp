#include "LoadAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI\Output.h"
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
	ifstream myFile(inputString); //opens the file

	if (myFile.is_open())
	{

		int id;
		
		int type_int;
		enum type
		{
			Rectangle
		};

		while (myFile >> type_int)			//reads from the file.
		{
			switch (type_int)
			{
			case Rectangle: {
				Point P1, P2;
				P1.x = 0; P1.y = 0;
				P2.x = 0; P2.y = 0;
				GfxInfo RectGfxInfo;
				CRectangle * R = new CRectangle(P1, P2, RectGfxInfo);
				R->Load(myFile);
				pManager->AddFigure(R);
				break; 
			}
			default:
				break; 
			}
		}
		myFile.close();
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		pOut->PrintMessage("Unable to open file");
	}

}
