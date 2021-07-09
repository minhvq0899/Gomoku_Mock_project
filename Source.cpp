#include "BoardManager.h"
#include "Login_Controller.h"
#include <iostream>
#include <string>
#include <vector>

// ====================================================== MAIN FUNCTION ======================================================
void loginProcess(Login_Controller& loginController) { 
	// Let the user input there user name and password
	bool login = false;
	int chooseFlag = 1;
	while (!login) {
		if (chooseFlag == NAME_INPUT) {
			loginController.loginView->nameInput();
			chooseFlag++;
		}
		else if (chooseFlag == PASS_INPUT) {
			loginController.loginView->passInput();
			chooseFlag++;
		}
		else if (chooseFlag == LOGIN_BUTTON) {
			if (loginController.loginView->loginInput()) {
				std::cout << "Clicked on Login" << chooseFlag << std::endl;
				break; 
			}
			else {
				chooseFlag++;
			}
		}
		else if (chooseFlag == REGISTER_BUTTON) {
			if (loginController.loginView->registerInput()) {
				std::cout << "Clicked on Register" << std::endl;
				break; 
			}
			else {
				chooseFlag++;
			}
		}
		else {
			chooseFlag = 1;
		}
	}

	// Decide if it's a login or a new register
	if (chooseFlag == 3) { // login

	} 
	else if (chooseFlag == 4) { // register
		// get info
		std::string new_userName(loginController.loginView->getUsername());
		std::string new_password(loginController.loginView->getPassname());
		// input that info into database
		loginController.mainDatabase->insertAccounts(new_userName, new_password); 
	}



}


void startProgram() {
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
				break;
			}
		}
	}

	bManager.replay();
	getchar();
}


int main() {
	Login_Controller loginController; 

	loginController.getLoginInfo();
	startProgram(); 

	getchar();

	return 0;
}