#include "SelectByType.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>

SelectByType::SelectByType(ApplicationManager * pApp) :Action(pApp)
{
	correct = 0;
	notCorrect = 0;
}

void SelectByType::ReadActionParameters() {
//empty
}
void SelectByType::Execute() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	//generate random shape
	int random = rand() % 5;
	switch (random) {
	case 0: {
		ActType = DRAW_LINE;
		pOut->PrintMessage("kindly, pick Lines. click anyway to continue :)");
	}
		break;
	case 1: {
		ActType = DRAW_RECT;
		pOut->PrintMessage("kindly, pick rectangles :) click anyway to continue");
	}
			break;
	case 2: {
		ActType = DRAW_TRI;
		pOut->PrintMessage("kindly, pick Triangles :) click anyway to continue");
	}
			break;
	case 3: {
		ActType = DRAW_RHOMBUS;
		pOut->PrintMessage("kindly, pick Rhombus :) click anyway to continue");
	}
			break;
	case 4: {
		ActType = DRAW_ELLIPSE;
		pOut->PrintMessage("kindly, pick Elipses :) click anyway to continue");
	}
			break;
	}
	pIn->GetUserAction();
	//get the number of that shape
	shapeNum = pManager->countSpecificFigures(ActType);
	
	do {
		Point p; pIn->GetPointClicked(p.x, p.y);
		CFigure *  tempFig = pManager->GetFigure(p.x,p.y);

		if (tempFig != NULL) {
			//find if it's correct
			switch (ActType)
			{
			case DRAW_RECT: {
				CRectangle * rect;
				rect = dynamic_cast<CRectangle *> (tempFig);
				if (rect != NULL) {
					pManager->DeleteFigure(tempFig);
					correct++;
				}
				else { notCorrect++; }
			}
			break;

			case DRAW_LINE: {
				CLine * line;
					line = dynamic_cast<CLine *> (tempFig);
					if (line != NULL) {
						pManager->DeleteFigure(tempFig);
						correct ++;
				}
					else { notCorrect++; }

			}
			break;

			case DRAW_RHOMBUS:{
				CRhombos * rho;

					rho = dynamic_cast<CRhombos *> (tempFig);
					if (rho != NULL) {
						pManager->DeleteFigure(tempFig);
						correct ++;
				}
					else { notCorrect++; }

			}
			break;

			case DRAW_ELLIPSE: {
				CEllipse * ell;

					ell = dynamic_cast<CEllipse *> (tempFig);
					if (ell != NULL) {
						pManager->DeleteFigure(tempFig);
						correct ++;
					
				}
					else { notCorrect++; }
			}
			break;

			case DRAW_TRI: {
				CTriangle * tri;

					tri = dynamic_cast<CTriangle *> (tempFig);
					if (tri != NULL) {
						pManager->DeleteFigure(tempFig);
						correct ++;
				}
					else { notCorrect++; }
			}
			break;
			}
		}
		pManager->UpdateInterface();
		pOut->PrintMessage("correct " + to_string(correct) + " , notCorrect " + to_string(notCorrect));
	} while (shapeNum != correct);
	pOut->PrintMessage("congratualtion! your score is: correct"  + to_string(correct) + " , notCorrect " + to_string(notCorrect));

	//Update the interface
}

SelectByType::~SelectByType()
{
}
