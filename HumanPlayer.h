#pragma once
#include "Player.h"
#include "Board.h"

typedef Player::Color Color;

class HumanPlayer : public Player {
public:
	HumanPlayer(Color _color);
	~HumanPlayer() override;
	void putPiece(char** ptrBoard, int i, int j) override;
};
