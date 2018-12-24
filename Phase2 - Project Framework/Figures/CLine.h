#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Point1;	
	Point Point2;

	
public:
	CLine(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	int GetLineLenght(int x1, int y1, int x2, int y2) const;

	virtual bool Isinsideboundaries(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;

	virtual bool Isinvalid();
	//M.A :create a function to check if the figure is valid to add to the list of figures or not.

	virtual void Save(ofstream &outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &myFile);	//Load the figure parameters to the file
};

#endif




























