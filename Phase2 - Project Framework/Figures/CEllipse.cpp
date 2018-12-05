#include "CEllipse.h"
#include <fstream>

CEllipse :: CEllipse(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Centre = P1;
	
}
	

void CEllipse::Draw(Output* pOut) const
{
	//Call Output::DrawEll to draw a rectangle on the screen	
	pOut->DrawEll(Centre, FigGfxInfo, Selected);
}

bool CEllipse::Isinsideboundaries(int x, int y) const
{
	double ElleqnRHS = (pow((x - Centre.x),2)) / (60 * 60 * 1.0) + (pow((y - Centre.y),2)) / (40 * 40 * 1.0);
	if (ElleqnRHS <= 1)
		return true;
	else
		return false;
}

void CEllipse::PrintInfo(Output * pOut) const
{
	double EllArea = cdPi * 60 * 40;

	string Ellinfo = "ID: " + to_string(ID) + ", Center : (" + to_string(Centre.x) + "," + to_string(Centre.y) + "), Area: " + to_string(EllArea);
	pOut->PrintMessage(Ellinfo);
}

void CEllipse::Save(ofstream &outFile) {
	outFile << 3 << "\t" << Centre.x << " " << Centre.y << "\t";
	outFile << "\t" << (int)FigGfxInfo.FillClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen;
	outFile << "\t" << (int)FigGfxInfo.DrawClr.ucBlue << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen;
	outFile << "\t" << FigGfxInfo.isFilled << "\n";
}
void CEllipse::Load(ifstream &myFile) {
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