#include "Board.h"
#include "BoardManager.h"
#include <iostream>

BoardManager::~BoardManager() {
	delete board;
	delete board_view;
}

BoardManager::BoardManager() {}

BoardManager::BoardManager(int size = 0) : board{ new Board(size) }, board_view{ new Board_View(size) } {}

bool BoardManager::getGameOver()
{
	return this->gameOver;
}

Board* BoardManager::getBoard()
{
	return board;
}




// 5 ký tự x/o liên tiếp là chiến thắng
Check_win BoardManager::checkWin(int r, int c, char player)
{
	Check_win CW;

	// ------------------------------------- Check Row -------------------------------------
	int count = 0;
	int r_temp = r;
	int c_temp = c;
	// Left
	while ((0 <= r_temp) && (r_temp < board->size) && (0 <= c_temp) && (c_temp < board->size) && count <= 4) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			c_temp -= 1;
		}
	}
	CW.startLine[0] = c_temp + 1;
	CW.startLine[1] = r_temp;

	c_temp = c;
	// Right
	while ((0 <= r_temp) && (r_temp < board->size) && (0 <= c_temp) && (c_temp < board->size)) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			c_temp += 1;
		}
	}
	CW.endLine[0] = c_temp - 1;
	CW.endLine[1] = r_temp;

	// Check if win by row
	if (count - 1 >= 5) {
		CW.win = true;
		std::cout << "Thang bang hang" << "\n";
		std::cout << "Check hang voi x1 = " << CW.startLine[0] << "\n";
		std::cout << "Check hang voi y1 = " << CW.startLine[1] << "\n";

		std::cout << "Check hang voi x2 = " << CW.endLine[0] << "\n";
		std::cout << "Check hang voi y2 = " << CW.endLine[1] << "\n";
		return CW;
	}


	// ------------------------------------- Check Column -------------------------------------
	count = 0;
	r_temp = r;
	c_temp = c;
	// Up
	while ((0 <= r_temp) && (r_temp < board->size) && (0 <= c_temp) && (c_temp < board->size) && count <= 4) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			r_temp -= 1;
		}
	}
	CW.startLine[0] = c_temp;
	CW.startLine[1] = r_temp + 1;
	r_temp = r;
	// Down
	while ((0 <= r_temp) && (r_temp < board->size) && (0 < c_temp) && (c_temp < board->size)) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			r_temp += 1;
		}
	}
	CW.endLine[0] = c_temp;
	CW.endLine[1] = r_temp - 1;
	// Check if win by Column
	if (count - 1 >= 5) {
		CW.win = true;
		std::cout << "Thang bang cot" << "\n";
		std::cout << "Check cot voi x1 = " << CW.startLine[0] << "\n";
		std::cout << "Check cot voi y1 = " << CW.startLine[1] << "\n";

		std::cout << "Check cot voi x2 = " << CW.endLine[0] << "\n";
		std::cout << "Check cot voi y2 = " << CW.endLine[1] << "\n";
		return CW;
	}


	// ------------------------------------- Check Diagonal -------------------------------------
	count = 0;
	r_temp = r;
	c_temp = c;
	// Diagonal Up Left
	while ((0 <= r_temp) && (r_temp < board->size) && (0 <= c_temp) && (c_temp < board->size) && count <= 4) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			r_temp -= 1;
			c_temp -= 1;
		}
	}
	CW.startLine[0] = c_temp + 1;
	CW.startLine[1] = r_temp + 1;
	r_temp = r;
	c_temp = c;
	// Diagonal Down Right
	while ((0 <= r_temp) && (r_temp < board->size) && (0 <= c_temp) && (c_temp < board->size)) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			r_temp += 1;
			c_temp += 1;
		}
	}
	CW.endLine[0] = c_temp - 1;
	CW.endLine[1] = r_temp - 1;
	// Check if win by diagonal
	if (count - 1 >= 5) {
		CW.win = true;
		std::cout << "Thang bang cheo len trai" << "\n";
		std::cout << "Check cheo voi x1 = " << CW.startLine[0] << "\n";
		std::cout << "Check cheo voi y1 = " << CW.startLine[1] << "\n";

		std::cout << "Check cheo voi x2 = " << CW.endLine[0] << "\n";
		std::cout << "Check cheo voi y2 = " << CW.endLine[1] << "\n";

		return CW;
	}


	// ------------------------------------- Check Diagonal -------------------------------------
	count = 0;
	r_temp = r;
	c_temp = c;
	// Diagonal Up Right
	while ((0 <= r_temp) && (r_temp < board->size) && (0 <= c_temp) && (c_temp < board->size) && count <= 4) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			r_temp -= 1;
			c_temp += 1;
		}
	}
	CW.startLine[0] = c_temp - 1;
	CW.startLine[1] = r_temp + 1;
	r_temp = r;
	c_temp = c;
	// Diagonal Down Left
	while ((0 <= r_temp) && (r_temp < board->size) && (0 <= c_temp) && (c_temp < board->size)) {
		if (board->ptrBoard[r_temp][c_temp] != player) {
			break;
		}
		else {
			count += 1;
			r_temp += 1;
			c_temp -= 1;
		}
	}
	CW.endLine[0] = c_temp + 1;
	CW.endLine[1] = r_temp - 1;
	// Check if win by diagnal
	if (count - 1 >= 5) {
		CW.win = true;
		std::cout << "Thang bang cheo len phai" << "\n";
		std::cout << "Check cheo voi x1 = " << CW.startLine[0] << "\n";
		std::cout << "Check cheo voi y1 = " << CW.startLine[1] << "\n";

		std::cout << "Check cheo voi x2 = " << CW.endLine[0] << "\n";
		std::cout << "Check cheo voi y2 = " << CW.endLine[1] << "\n";
		return CW;
	}

	return CW;
}



void BoardManager::getMove(char move)
{
	mouseData raw_pixel, converAxis, convertPixel;
	raw_pixel = board_view->clickEventHandling();

	converAxis = board_view->convertToAxis(raw_pixel);

	// check move
	if (converAxis.x < board->size * SIZE_BOX && converAxis.y < board->size * SIZE_BOX) {
		bool validMove = board->isValidInput(converAxis.y, converAxis.x, move);
		if (validMove) {
			board_view->Fill_Move(raw_pixel.x, raw_pixel.y, move);
			board->moveST++;
		}
	}
	else {
		std::cout << "The move is not valid. Please try another move" << std::endl;
	}

	// store most recently clicked axis
	this->x_axisGlobal = converAxis.x;
	this->y_axisGlobal = converAxis.y;
}

void BoardManager::drawWinningLine(int i1, int j1, int i2, int j2) {
	board_view->Draw_LineOver(i1, j1, i2, j2);
}


void BoardManager::printBoard() {
	board->printBoard();
}

void BoardManager::replay() {
	board_view->Set_gameOver(); 
}
