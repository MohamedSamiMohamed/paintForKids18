#include "CLine.h"
#include <fstream>
CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	//Setting an ID for the figure
	ID = IDSetter++;

	FigGfxInfo.FillClr = LIGHTGOLDENRODYELLOW; //M.A:Setting to any don't care color

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
	int Lenght1 = GetLineLenght(x, y, Point1.x, Point1.y);
	int Lenght2 = GetLineLenght(x, y, Point2.x, Point2.y);
	int Lenghttotal = GetLineLenght(Point2.x, Point2.y, Point1.x, Point1.y);

	if (Lenghttotal <= Lenght1 + Lenght2 + 1 && Lenghttotal >= Lenght1 + Lenght2)
	{
		return true;
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

//M.A : to check for invalid area of drawinh the line
bool CLine::Isinvalid()
{
	if (Point1.y <= UI.ToolBarHeight || Point2.y <= UI.ToolBarHeight
		|| (Point1.y > UI.height - UI.StatusBarHeight) || (Point2.y > UI.height - UI.StatusBarHeight))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int CLine::GetLineLenght(int x1, int y1, int x2, int y2) const
{
	int lenght = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return lenght;
}
