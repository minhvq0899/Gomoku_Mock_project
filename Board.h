#ifndef BOARD_H
#define BOARD_H

struct Board {
	char** ptrBoard;
	int size;
	int moveST = 0;
	~Board();
	Board();
	Board(int);

	void updateBoard(int, int, char) const;
	void printBoard() const;
	bool isValidInput(int, int, char) const;
};


#endif // BOARD_H