#pragma once
#include "Action.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CEllipse.h"
#include "../Figures/CLine.h"
#include "../Figures/CRhombos.h"
#include "../Figures/CTriangle.h"
#include "../Actions/SaveAction.h"

class SelectByType :public Action
{
	ActionType ActType;
	int correct;
	int notCorrect;
	int shapeNum;
public:
	SelectByType(ApplicationManager * pApp);
	~SelectByType();
	void ReadActionParameters();
	void Execute();
};

