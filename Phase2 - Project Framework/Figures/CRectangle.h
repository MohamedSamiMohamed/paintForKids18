#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	virtual bool Isinsideboundaries(int x, int y) const;

	virtual bool Isinvalid();

	virtual void Save(ofstream &outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &myFile);	//Load the figure parameters to the file
	void PrintInfo(Output* pOut) const;
};

#endif