#include <vector>
#include "HumanPlayer.h"
#include "Board.h"
using namespace std;

HumanPlayer::~HumanPlayer() {}

HumanPlayer::HumanPlayer(Color _color) : Player() {
	this->color = _color;
}

void HumanPlayer::putPiece(char** ptrBoard, int i, int j) {
	switch (color) {
	case Color::black:
	{
		ptrBoard[i][j] = 'x';
		break;
	}
	case Color::white:
	{
		ptrBoard[i][j] = 'o';
		break;
	}
	default:
	{
		throw "Something wrong!";
	}
	}

}

