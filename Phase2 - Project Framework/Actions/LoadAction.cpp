#include "LoadAction.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombos.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI\Output.h"
#include <iostream>


LoadAction::LoadAction(ApplicationManager * pApp) :Action(pApp)
{}


void LoadAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if(UI.InterfaceMode==MODE_DRAW)
	{
	if(pManager->Replay=true)
		inputString = "temp";
	pOut->PrintMessage("please enter the file name to be loaded");
	inputString = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	}
	else 
		inputString = "temp";
}


void LoadAction::Execute() {
	
	ReadActionParameters();
	inputString = inputString + ".txt";
	ifstream myFile(inputString); //opens the file
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (myFile.is_open())
	{
		pManager->deleteAll();

		int type_int;
		enum type
		{
			Rectangle,
			Ellipse,
			Line,
			Rhombos,
			Triangle
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
				CRectangle * shape = new CRectangle(P1, P2, RectGfxInfo);
				shape->Load(myFile);
				pManager->AddFigure(shape);
				break; 
			}
			case Ellipse: {
				Point P1;
				P1.x = 0; P1.y = 0;
				GfxInfo RectGfxInfo;
				CEllipse * shape = new CEllipse(P1, RectGfxInfo);
				shape->Load(myFile);
				pManager->AddFigure(shape);
				break;
			}
			case Line: {
				Point P1, P2;
				P1.x = 0; P1.y = 0;
				P2.x = 0; P2.y = 0;
				GfxInfo RectGfxInfo;
				CLine * shape = new CLine(P1, P2, RectGfxInfo);
				shape->Load(myFile);
				pManager->AddFigure(shape);
				break;
			}
			case Rhombos: {
				Point P1;
				P1.x = 0; P1.y = 0;
				GfxInfo RectGfxInfo;
				CRhombos * shape = new CRhombos (P1, RectGfxInfo);
				shape->Load(myFile);
				pManager->AddFigure(shape);
				break;
			}
			case Triangle: {
				Point P1, P2,P3;
				P1.x = 0; P1.y = 0;
				P2.x = 0; P2.y = 0;
				P3.x = 0; P3.y = 0;
				GfxInfo RectGfxInfo;
				CTriangle * shape = new CTriangle(P1, P2,P3, RectGfxInfo);
				shape->Load(myFile);
				pManager->AddFigure(shape);
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
		pOut->PrintMessage("Unable to open file");
	}

}


