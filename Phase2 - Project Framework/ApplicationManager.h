#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	int ExistNum [6];
	
	 

public:	
	int Play;
 	bool Replay;
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window

	// -- Select Action Functions
	void setselectedfig(CFigure* pFig); //M.a: Sets a figure to be selected
	CFigure* Getselectedfigure() const; //M.a: Returns the current selected figure
	void SetSelectedfigNULL(); //M.A: To set selcted figure to NULL

	// -- Save/Load Action functions
	void SaveAll(ofstream &outFile);
	void SaveByTypeFn(ofstream &outFile, ActionType A);
	void deleteAll();
	bool isEmpty();
	bool isFound(ActionType);

	// -- Delete Action Functions
	void DeleteFigure(CFigure* pFig); //M.A: searches for the selected figure,Deletes it,then shifts the whole array and decreases fig count
	
	//-- Play Mode actions
	int TypeRandom();
	int* ExistM ();
    void playMessage(int r);
    void play (CFigure* &playFigure ,int r,int& Count,int& Correct,int& NonCorrect);
	int NumCertainShapes(int r);

	// -- Swaping Functions
	void SwapBackward(CFigure* pFig); //M.A:to send a Figure one step Backward
	void SwapForward(CFigure* pFig);
	

};

#endif