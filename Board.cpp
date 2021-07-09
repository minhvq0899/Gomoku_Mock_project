#include "Board.h"

#include <iostream>


// Destructor 
Board::~Board() {
	for (int i = 0; i < size; i++) {
		delete[] ptrBoard[i];
	}
	delete[] ptrBoard;
}

// Constructor data structure
Board::Board() {}

Board::Board(int size = 0) : size{ size } {
	ptrBoard = new char* [size];

	for (int i = 0; i < size; i++)
		ptrBoard[i] = new char[size];
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {
			ptrBoard[i][j] = '-';
		}
}



// helper functions
// Update ptrBoard
void Board::updateBoard(int i, int j, char player) const {
	this->ptrBoard[i][j] = player; 
}


// Print Board
void Board::printBoard() const {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << ptrBoard[i][j] << " ";
		}
		std::cout << "\n";
	}
}

// Check valid input?
bool Board::isValidInput(int i, int j, char player) const {
	if ( (ptrBoard[i][j] == 'x') || (ptrBoard[i][j] == 'o') )
		return false;
	else {
		// update board
		updateBoard(i, j, player); 
		return true;
	}
}