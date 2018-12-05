#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

enum color_project {
	Black1,
	WHITE1,
	RED1,
	GREEN1,
	BLUE1
};
class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	static int count;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream &outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &myFile);	//Load the figure parameters to the file
};

#endif