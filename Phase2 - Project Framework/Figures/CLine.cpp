#include "CLine.h"
#include <fstream>
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	//Setting an ID for the figure
	ID = IDSetter++;

	Point1 = P1;
	Point2 = P2;
}
	

void CLine::Draw(Output* pOut) const
{
	if (isDrawn)
	//Call Output::DrawLine to draw a line on the screen	
	pOut->DrawLine(Point1, Point2, FigGfxInfo, Selected);
}

bool CLine::Isinsideboundaries(int x, int y) const
{  
	if ((x <= Point1.x && x >= Point2.x) || (x <= Point2.x && x >= Point1.x))
	{
		float slope = (Point2.y - Point1.y)*1.0 / (Point2.x - Point1.x);
		float Y_intecept = Point1.y - slope * Point1.x;
		//M.A : Right Hand Side of the line equation
		int EqnRHS = y - slope * x - Y_intecept;
		if (EqnRHS == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void CLine::PrintInfo(Output * pOut) const
{
	//M.A : To find the line length
	int Linelength = sqrt(pow((Point2.x - Point1.x), 2) + pow((Point2.y - Point1.y), 2));
	string lineinfo = "ID =" + to_string(ID) + ", P1 : (" + to_string(Point1.x) + "," + to_string(Point1.y) + ")" + ", P2 : (" + to_string(Point2.x) + "," + to_string(Point2.y) + ")" + ", Lenght : " + to_string(Linelength);
	pOut->PrintMessage(lineinfo);
}

void CLine::Save(ofstream &outFile) {
	outFile << 2 << " " << ID << " " << Point1.x << " " << Point1.y << " " << Point2.x << " " << Point2.y;
	outFile << " " << (int)FigGfxInfo.FillClr.ucBlue << " " << (int)FigGfxInfo.FillClr.ucRed << " " << (int)FigGfxInfo.FillClr.ucGreen;
	outFile << " " << (int)FigGfxInfo.DrawClr.ucBlue << " " << (int)FigGfxInfo.DrawClr.ucRed << " " << (int)FigGfxInfo.DrawClr.ucGreen;
	outFile << " " << FigGfxInfo.isFilled << "\n";
}
void CLine::Load(ifstream &myFile) {
	myFile >> ID;
	myFile >> Point1.x >> Point1.y >> Point2.x >> Point2.y;

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