#include "Board_View.h"


int lastX = -1;
int lastY = -1;

Board_View::Board_View() {}

Board_View::Board_View(int numberBox) {
	initwindow((numberBox + 0.5) * SIZE_BOX, (numberBox + 0.5) * SIZE_BOX, "Caro Game");
	setbkcolor(BKCOLOR);

	cleardevice();

	for (int i = 0; i <= numberBox; i++)
	{
		line(i * SIZE_BOX, 0, i * SIZE_BOX, numberBox * SIZE_BOX);
		line(0, i * SIZE_BOX, numberBox * SIZE_BOX, i * SIZE_BOX);
		setcolor(BLACK);
	}
}

Board_View::~Board_View() {}

//login_info Board_View::Login() {
//	// Viết đè lên console đã có sẵn để người chơi nhập account hoặc register new account 
//	// return a struct trong đó có chưa thông tin người chơi nhập vào
//}

void Board_View::Fill_Move(int x, int y, char move)
{
	//Fill_move
	/*while (!ismouseclick(WM_LBUTTONDOWN)) {}; */
	int a = x / SIZE_BOX;
	int b = y / SIZE_BOX;
	switch (move)
	{
	case 'x':
		setcolor(RED);
		line(10 + a * SIZE_BOX, 10 + b * SIZE_BOX, 20 + a * SIZE_BOX, 20 + b * SIZE_BOX);
		line(10 + a * SIZE_BOX, 20 + b * SIZE_BOX, 20 + a * SIZE_BOX, 10 + b * SIZE_BOX);
		break;
	case 'o':
		setcolor(GREEN);
		circle(15 + a * SIZE_BOX, 15 + b * SIZE_BOX, 7);
		break;
	}
}

void Board_View::Draw_LineOver(int i_first, int j_first, int i_last, int j_last) {
	setcolor(LIGHTBLUE);
	line(SIZE_BOX / 2 + SIZE_BOX * i_first, SIZE_BOX / 2 + SIZE_BOX * j_first, SIZE_BOX / 2 + SIZE_BOX * i_last, SIZE_BOX / 2 + SIZE_BOX * j_last);
}


int* Board_View::convertAxis(int x, int y)
{
	int result[2];
	result[0] = (x / SIZE_BOX);
	result[1] = (y / SIZE_BOX);
	return result;
}

int* Board_View::convertPixel(int i, int j)
{
	int result[2];
	result[0] = (SIZE_BOX / 2) + (SIZE_BOX * (i));
	result[1] = (SIZE_BOX / 2) + (SIZE_BOX * (j));
	return result;
}

void Board_View::lightBox(int x, int y, int color)
{
	int left, right;
	setfillstyle(SOLID_FILL, color);
	int* a = convertAxis(x, y);
	int* b = convertPixel(*a, *(a + 1));
	bar(*b - ((SIZE_BOX - 1) / 2), *(b + 1) - ((SIZE_BOX - 1) / 2), *b + (SIZE_BOX / 2), *(b + 1) + (SIZE_BOX / 2));
	lastX = x;
	lastY = y;
}

void Board_View::Set_gameOver()
{
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(250, 250, "GAME OVER...\nCLICK MOUSE TO CONTINUE...");
	while (!ismouseclick(WM_LBUTTONDOWN)) {};
	cleardevice();
	setcolor(RED);
	settextstyle(3, HORIZ_DIR, 5);

	//outtextxy(250, 250, "Game over...");
	rectangle(125, 210, 375, 270);
	rectangle(125, 310, 375, 370);
	outtextxy(250, 250, "REPLAY");
	outtextxy(250, 350, "End");
}

mouseData Board_View::convertToAxis(mouseData data)
{
	mouseData newData;
	// convert pixel -> axis
	newData.x = (data.x / SIZE_BOX);
	newData.y = (data.y / SIZE_BOX);
	return newData;
}

