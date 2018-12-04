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
	outFile << "Rectangle\t" << ID << "\n";// << "\t(" << "," << Corner2 << FigGfxInfo.DrawClr << "\n";
}

void CRectangle::Load(ifstream &myFile) {
	int color_draw, color_fill;
	color clr_draw, clr_fill;
	enum color_project {
		Black1,
		WHITE1,
		RED1,
		GREEN1,
		BLUE1
	};

	myFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;

	//get drawing, filling colors and pen width from the file

	myFile >> color_draw >> color_fill;
	switch (color_draw) {
	case WHITE1:
		clr_draw = WHITE;
		break;
	}
	switch (color_fill) 
	{
	case WHITE1:
		clr_draw = WHITE;
		break;
	}
	FigGfxInfo.DrawClr = clr_draw;
	FigGfxInfo.FillClr = clr_fill;
}
