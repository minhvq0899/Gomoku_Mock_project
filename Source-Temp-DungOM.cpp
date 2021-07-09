//#include "Design_Table.h"
#include "BoardManager.h"
#include <iostream>
// ====================================================== MAIN FUNCTION ======================================================
int main() {
	int size = 10;
	BoardManager bManager(20);

	while (!bManager.getGameOver()) {
		if (bManager.getBoard()->moveST % 2 == 0) {
			bManager.getMove('x');
			// ----------- print board each step to see if moves are store in the actual board ----------- 
			bManager.printBoard();
			std::cout << bManager.x_axisGlobal; 
			std::cout << bManager.y_axisGlobal << "\n";
			std::cout << "\n";
			// -------------------------------------------------------------------------------------------
			// check win
			Check_win CW = bManager.checkWin(bManager.x_axisGlobal, bManager.y_axisGlobal, 'x'); 

			if (CW.win) {
				std::cout << "X Win\n";
				bManager.drawWinningLine(CW.startLine[0], CW.startLine[1], CW.endLine[0], CW.endLine[1]); 
				Set_gameOver();
				break; 
			}
		}
		else {
			bManager.getMove('o');
			// ----------- print board each step to see if moves are store in the actual board ----------- 
			bManager.printBoard();
			std::cout << "\n";
			std::cout << bManager.x_axisGlobal;
			std::cout << bManager.y_axisGlobal << "\n";
			// -------------------------------------------------------------------------------------------
			// check win
			Check_win CW = bManager.checkWin(bManager.x_axisGlobal, bManager.y_axisGlobal, 'o');

			if (CW.win) {
				std::cout << "O Win\n";
				// draw line
				bManager.drawWinningLine(CW.startLine[0], CW.startLine[1], CW.endLine[0], CW.endLine[1]);
				Set_gameOver();
				break; 
			}
		}
	}
	
	getchar();

	return 0;
}