#include "CRectangle.h"
#include <fstream>
#include <iostream>

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	//Setting an ID for the figure
	ID = IDSetter++;

	Corner1 = P1;
	Corner2 = P2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}


bool CRectangle::Isinsideboundaries(int x, int y) const
{
	//M.A : to check the position of the two corners 
	int check_X_first = Corner1.x - Corner2.x;
	int check_Y_first = Corner1.y - Corner2.y;

	if (check_X_first < 0)
	{
		if (check_Y_first < 0)
		{
			if (x >= Corner1.x && x <= Corner2.x && y >= Corner1.y && y <= Corner2.y)
				return true;
			else
				return false;
		}
		else if (check_Y_first > 0)
		{
			if (x >= Corner1.x && x <= Corner2.x && y >= Corner2.y && y <= Corner1.y)
				return true;
			else
				return false;
		}
	}
	else if(check_X_first > 0)
	{
		if (check_Y_first < 0)
		{
			if (x >= Corner2.x && x <= Corner1.x && y >= Corner1.y && y <= Corner2.y)
				return true;
			else
				return false;
		}
		else if (check_Y_first > 0)
		{
			if (x >= Corner2.x && x <= Corner1.x && y >= Corner2.y && y <= Corner1.y)
				return true;
			else
				return false;
		}

    }
}


void CRectangle::PrintInfo(Output* pOut) const
{
	int width, height;
	width = abs(Corner1.x - Corner2.x);
	height = abs(Corner1.y - Corner2.y);
	string info = "ID: " + to_string(ID) + ", Height : " + to_string(height) + ", Width : " + to_string(width);
	
    pOut->PrintMessage(info);
}

void CRectangle::Save(ofstream &outFile) {
	outFile << 0 << " " << ID << " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y;
	outFile << " " << (int)FigGfxInfo.FillClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen;
	outFile << " " << (int)FigGfxInfo.DrawClr.ucBlue << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen;
	outFile << " " << FigGfxInfo.isFilled << "\n";
}

void CRectangle::Load(ifstream &myFile) {
	myFile >> ID;

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


