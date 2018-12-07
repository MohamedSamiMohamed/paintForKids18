#include "SelectByType.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>

SelectByType::SelectByType(ApplicationManager * pApp) :Action(pApp)
{}

void SelectByType::ReadActionParameters() {
//empty
}
void SelectByType::Execute() {
}

SelectByType::~SelectByType()
{
}
