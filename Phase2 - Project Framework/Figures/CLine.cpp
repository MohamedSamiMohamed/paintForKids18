#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Point1 = P1;
	Point2 = P2;
}
	

void CLine::Draw(Output* pOut) const
{
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

}
void CLine::Load(ifstream &myFile) {

}