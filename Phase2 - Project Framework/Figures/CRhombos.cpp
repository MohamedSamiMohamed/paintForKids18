#include "CRhombos.h"
#include <fstream>
CRhombos::CRhombos(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	//Setting an ID for the figure
	ID = IDSetter++;

	Centre = P1;
}
	

void CRhombos::Draw(Output* pOut) const
{
	//Call Output::DrawRhom to draw a rhombos on the screen	
	pOut->DrawRhom(Centre, FigGfxInfo, Selected);
}

bool CRhombos::Isinsideboundaries(int x, int y) const
{
	//M.A : Right hand side of the rhombus equation considering the coordinates at its center
	float RhomeqnRHS = abs(x - Centre.x) / (40.0) + abs(y - Centre.y) / (50.0);
	//M.A : if it is on one of the four rhombus sides or inside it
	if (RhomeqnRHS <= 1)
		return true;
	else
		return false;
}

void CRhombos::PrintInfo(Output * pOut) const
{
	string rhominfo = "ID: " + to_string(ID) + ", Center : (" + to_string(Centre.x) + "," + to_string(Centre.y) + ")";
	pOut->PrintMessage(rhominfo);
}

void CRhombos::Save(ofstream &outFile) {
	outFile << 3 << " " <<ID << " " << Centre.x << " " << Centre.y << " ";
	outFile << " " << (int)FigGfxInfo.FillClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen;
	outFile << " " << (int)FigGfxInfo.DrawClr.ucBlue << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen;
	outFile << " " << FigGfxInfo.isFilled << "\n";
}
void CRhombos::Load(ifstream &myFile) {
	myFile >> ID;
	myFile >> Centre.x >> Centre.y;

	//get drawing, filling colors and pen width from the file
	int B, R, G;

	myFile >> B >> R >> G;
	FigGfxInfo.FillClr.ucBlue = (char)B;
	FigGfxInfo.FillClr.ucRed = (char)R;
	FigGfxInfo.FillClr.ucGreen = (char)G;

	myFile >> B >> R >> G;
	FigGfxInfo.DrawClr.ucBlue = (char)B;
	FigGfxInfo.DrawClr.ucRed = (char)R;
	FigGfxInfo.DrawClr.ucGreen = (char)G;

	int IsFilled;
	myFile >> IsFilled;
	FigGfxInfo.isFilled = IsFilled;
}