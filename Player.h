#include "Board.h"
#ifndef GOMOKU_PLAYER_H
#define GOMOKU_PLAYER_H

class Player {
public:

	virtual ~Player();
	Player();
	enum class Color { black, white };

	Color getColor() const {
		return color;
	}

	virtual void putPiece(char** ptrBoard, int i, int j) = 0;

protected:
	Color color;
};

typedef Player::Color Color;

#endif //GOMOKU_PLAYER_H
