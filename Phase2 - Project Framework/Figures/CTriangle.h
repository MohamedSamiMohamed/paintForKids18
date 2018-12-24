#ifndef CTRI_H
#define CTRI_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point , Point, Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;

	//M.A : Finding the area of triangle using its vertices needed in isinsideboundaries function.
	float GetTriArea(int x1, int y1, int x2, int y2, int x3, int y3) const;

	virtual bool Isinsideboundaries(int x, int y) const;

	virtual bool Isinvalid();

	virtual void PrintInfo(Output* pOut) const;

	virtual void Save(ofstream &outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &myFile);	//Load the figure parameters to the file
};


#endif
