#pragma once
#include <vector>
#include "Board.h"
#include "Board_View.h"
#include "Player.h"

// Struct Check_win
struct Check_win {
	bool win = false;
	int startLine[2];
	int endLine[2];
};


class BoardManager {
private:
	Board* board;
	Board_View* board_view;
	bool gameOver = false; 
public:
	~BoardManager();
	BoardManager();
	BoardManager(int);
	bool getGameOver();
	Board* getBoard();
	Check_win checkWin(int, int, char); 
	int x_axisGlobal; 
	int y_axisGlobal;
	void getMove(char);
	void drawWinningLine(int, int, int, int); 
	void printBoard(); 
	void replay(); 
};