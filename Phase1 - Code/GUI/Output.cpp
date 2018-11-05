#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1200;
	UI.height = 650;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;
	
	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////*****BH****
void Output::ClearToolBar() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0, UI.width, UI.StatusBarHeight);
	
}
////////////////////////////////////////////////////////////////////////////////////////****BH*****
void Output :: TO_PLAY() const {
	ClearToolBar();
	CreatePlayToolBar();

}
////////////////////////////////////////////////////////////////////////////////////////****MS*****
void Output:: TO_DRAW()const{
  ClearToolBar();
  CreateDrawToolBar();
}

//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_PLAY] = "images\\MenuItems\\ITM_PLAY.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\Menu_Line.jpg";
	MenuItemImages[ITM_RHOMBUS] = "images\\MenuItems\\Menu_Rhom.jpg";
	MenuItemImages[ITM_ELLIPSE] = "images\\MenuItems\\Menu_ELLIPSE.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\Menu_Trian.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Select.jpg";
	MenuItemImages[ITM_DRAW_CLR] = "images\\MenuItems\\DRAW_CLR.jpg";
	MenuItemImages[ITM_FILL_CLR] = "images\\MenuItems\\FILL_CLR.jpg";
	MenuItemImages[ITM_RED] = "images\\MenuItems\\Red.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Blue.jpg";
	MenuItemImages[ITM_WHITE] = "images\\MenuItems\\White.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Green.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Black.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\Paste.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\Save.jpg";
	MenuItemImages[ITM_SAVE_BY_TYPE] = "images\\MenuItems\\SAVE_BY_TYPE.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\Load.jpg";



	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const   //****MS****
{
	UI.InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";
	MenuItemImages[ITM_FIGTYPE] = "images\\MenuItems\\ITM_FIGTYPE.jpg";
	MenuItemImages[ITM_FIGCOL] = "images\\MenuItems\\ITM_FIGCOL.jpg";
	MenuItemImages[ITM_DRAW] = "images\\MenuItems\\ITM_DRAW.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar	
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
	
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

//============================================================================================================//
void Output::DrawRhom(Point P1, GfxInfo RhomGfxInfo, bool selected) const      /*M.A : The function takes P1 from the user click then derives
																			   two arrays one foe x vertices and the other for y vertices from the 
																			   center point (x,y+50) (x+40,y) (x,y-50) (x-40,y) then if sends the two arrays
																			   to drawpolygon function and 4 which is the number of vertices and the style
																			   filled or nonfilled*/
{

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor;
	else
		DrawingClr = UI.DrawColor;  //setting draw colour

	 int* px = new int [4];
	 int* py = new int [4];              

	 px[0] = P1.x;
	 px[1] = P1.x + 80;
	 px[2] = P1.x;
	 px[3] = P1.x - 80;                              //M.A :setting an array of x values for vertices

	 py[0] = P1.y + 100;
	 py[1] = P1.y;
	 py[2] = P1.y - 100;
	 py[3] = P1.y;                                   //M.A :setting an array of y values for vertices

	 pWind->SetPen(DrawingClr, 1);
	 
	 drawstyle style;
	 if (RhomGfxInfo.isFilled)
	 {
		 style = FILLED;
		 pWind->SetBrush(RhomGfxInfo.FillClr);
	 }
	 else
		 style = FRAME;                              //M.A :identify filled or frame

	 pWind->DrawPolygon(px, py, 4, style);       //M.A :where px and py are arrays of vertices derived from center point
	 
	 delete[]px;
	 delete[]py;                                   
}
//==============================================================================================//
void Output::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo, bool selected ) const {  //Draw a line
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 5);
	drawstyle style;
	style = FRAME;

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
}

void Output::DrawTri(Point p1,Point p2,Point p3, GfxInfo TriGfxInfo, bool selected)const  //****MS*****
{
	color DrawingClr;
	if (selected)
		DrawingClr=UI.HighlightColor;
	else 
		DrawingClr=TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,1);
	drawstyle style;
	if(TriGfxInfo.isFilled)
	{
	style =FILLED;
	pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else 
		style =FRAME;
	pWind->DrawTriangle(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,style);
	}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

