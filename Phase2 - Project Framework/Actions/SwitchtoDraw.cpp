#include "SwitchtoDraw.h"
#include"..\ApplicationManager.h"
#include<fstream>
#include "..\Figures\CRectangle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombos.h"
#include "..\Figures\CTriangle.h"



SwitchtoDraw::SwitchtoDraw(ApplicationManager* pApp):Action(pApp)
{}


void SwitchtoDraw :: ReadActionParameters()
{}


void SwitchtoDraw :: Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->ExecuteAction(LOAD);
	
	pOut ->CreateDrawToolBar();
}

