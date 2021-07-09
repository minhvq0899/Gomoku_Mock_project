#pragma once
#include"graphics.h"
class Table
{
private:
	char move[20][20];
	int countMove;

public:
	void setMove(int, int, char);
	char getMove();
	void setCountMove(int);
	int getCountMove();
};

