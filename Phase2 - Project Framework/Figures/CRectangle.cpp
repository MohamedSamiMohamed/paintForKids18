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
void CRectangle::Load(ifstream &inFile) {
	string line;
	int id;
	string type;
	while (inFile >> type >> id)
	{
		cout << type << " " << id << "\n";
	}
	//pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
	
}
