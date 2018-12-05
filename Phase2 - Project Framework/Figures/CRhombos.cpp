#include "CRhombos.h"

CRhombos::CRhombos(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
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

}
void CRhombos::Load(ifstream &myFile) {

}