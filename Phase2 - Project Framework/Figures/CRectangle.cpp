#include "CRectangle.h"
#include <fstream>
#include <iostream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}
	
void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
	
}
int CRectangle::count = 0;
void CRectangle::Save(ofstream &outFile) {
	ID = ++count;
	outFile << 0 << "\t" << Corner1.x << " " << Corner1.y << "\t" << Corner2.x << " " << Corner2.y;
	outFile << "\t" << (int)FigGfxInfo.FillClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen;// << "\t(" << "," << Corner2 << FigGfxInfo.DrawClr << "\n";
	outFile << "\t" << (int)FigGfxInfo.DrawClr.ucBlue << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen;// << "\t(" << "," << Corner2 << FigGfxInfo.DrawClr << "\n";
	outFile << "\t" <<FigGfxInfo.isFilled << "\n";
}

void CRectangle::Load(ifstream &myFile) {
	myFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;

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
