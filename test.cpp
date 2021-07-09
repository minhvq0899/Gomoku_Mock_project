#include <iostream>
#include <vector>
#include "Node.h"
#include "Board.h"
#include "HumanPlayer.h"

using namespace std;
using namespace GOMOKU;

typedef Node::State State;
typedef Player::Color Color;

int main() {
    cout << "Set up game\n";
    int size = 6;
    Board ChessBoard;
    ChessBoard.initBoard(size);

    HumanPlayer human1(Color::white);
    HumanPlayer human2(Color::black);

    Player* p1 = &human1;
    Player* p2 = &human2;

    cout << "Play game: \n";
    int i = 0;
    do {
        bool isValid;
        do {
            int i , j;
            cout << "player1 lay chess piece: ";
            cin >> i >> j;
            isValid = ChessBoard.isValidInput(i,j);
            p1->putPiece(ChessBoard, i, j);
            cout << endl;
        } while (isValid ^= true);

        do {
            int i, j;
            cout << "player2 lay chess piece: ";
            cin >> i >> j;
            isValid = ChessBoard.isValidInput(i, j);
            p2->putPiece(ChessBoard, i, j);
            cout << endl;
        } while (isValid ^= true);

        i++;

    } while (i < 3);
    
    ChessBoard.printBoard();

    return 0;
}
