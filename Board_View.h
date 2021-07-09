#pragma once
#include "graphics.h"
#include "Mouse_Event.h"
#define SIZE_BOX 30
#define BKCOLOR WHITE

struct login_info
{
	bool new_account = false;
	char account_name[256];
	char account_password[256];
};


class Board_View: public Mouse_Event
{
public:
	Board_View();
	Board_View(int);
	~Board_View();

	// login_info Login();
	void Fill_Move(int, int, char);
	void Draw_LineOver(int, int, int, int);
	int* convertAxis(int, int);
	int* convertPixel(int, int);
	void lightBox(int, int, int);
	void Set_gameOver();
	mouseData convertToAxis(mouseData);
};


