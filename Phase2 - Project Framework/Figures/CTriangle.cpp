#include "CTriangle.h"
#include <fstream>

CTriangle::CTriangle(Point P1, Point P2,Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	//Setting an ID for the figure
	ID = IDSetter++;

	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
}
	

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a rectangle on the screen	
	pOut->DrawTri(Corner1, Corner2,Corner3, FigGfxInfo, Selected);
}

float CTriangle::GetTriArea(int x1, int y1, int x2, int y2, int x3, int y3) const
{
	float area = fabs(0.5*(x1 * (y2 - y3) - x2 * (y1 - y3) + x3 * (y1 - y2)));
	return area;
}

bool CTriangle::Isinsideboundaries(int x, int y) const
{
	//M.A :finding the total area of the triangle
	int Areatotal = GetTriArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	//M.A :finding the areas of the three triangles created by the point
	int Area1 = GetTriArea(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	int Area2 = GetTriArea(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	int Area3 = GetTriArea(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);

	if (Area1 + Area2 + Area3 == Areatotal)
		return true;
	else
		return false;
}

void CTriangle::PrintInfo(Output * pOut) const
{
	
	string Triinfo = "ID: " + to_string(ID) + ", P1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + ")" + ", P2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + ")";
	Triinfo += ", P3: (" + to_string(Corner3.x) + "," + to_string(Corner3.y) + ")";
	
	pOut->PrintMessage(Triinfo);
}

void CTriangle::Save(ofstream &outFile) {
	outFile << 4 << " "<< ID <<" " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << Corner3.x << " " << Corner3.y;
	outFile << " " << (int)FigGfxInfo.FillClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen;
	outFile << " " << (int)FigGfxInfo.DrawClr.ucBlue << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen;
	outFile << " " << FigGfxInfo.isFilled << "\n";
}

void CTriangle::Load(ifstream &myFile) {
	myFile >> ID;
	myFile >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;

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


