#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRhombos : public CFigure
{
private:
	Point Centre;	

public:
	CRhombos(Point , GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	virtual bool Isinsideboundaries(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;
	virtual void Save(ofstream &outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &myFile);	//Load the figure parameters to the file
};

#endif




























