#include "Login_Controller.h"


Login_Controller::Login_Controller() : mainDatabase{ new Database() }, loginView{ new Login_View() } {}

Login_Controller::~Login_Controller() {
	delete mainDatabase;
	delete loginView;
}


void Login_Controller::getLoginInfo() {
	int chooseFlag = 1;
	isValidRegister = false;
	
	loginView->Init_Login();
	while (!isLogin) {

		if (chooseFlag == NAME_INPUT) {

			loginView->nameInput();
			chooseFlag = PASS_INPUT;
		}

		else if (chooseFlag == PASS_INPUT) {

			loginView->passInput();
			chooseFlag = LOGIN_BUTTON;
		}

		else if (chooseFlag == LOGIN_BUTTON) {
			if (loginView->loginInput()) {
				std::cout << "Send to database" << std::endl;
				std::cout << "User Name: " << loginView->getUsername() << std::endl;
				std::cout << "Pass Name: " << loginView->getPassname() << std::endl;
			}
			else {
				chooseFlag = REGISTER_BUTTON;
			}
		}
		else if (chooseFlag == REGISTER_BUTTON) {
			if (loginView->registerInput()) {
				closegraph();
				getRegisterInfo();
			}
			else {
				chooseFlag = NAME_INPUT;
			}
		}
		else {
			chooseFlag = NAME_INPUT;
		}

	}
}



void Login_Controller::getRegisterInfo() {
	int registerFlag = NAME_INPUT;
	Register_View* register_view = new Register_View();
	register_view->Init_Register();
	while (!isValidRegister) {

		if (registerFlag == NAME_INPUT) {

			register_view->nameInput();
			registerFlag = PASS_INPUT;
		}

		else if (registerFlag == PASS_INPUT) {

			register_view->passInput();
			registerFlag = REPASS_INPUT;
		}

		else if (registerFlag == REPASS_INPUT) {

			register_view->repassInput();
			registerFlag = REGISTER_BUTTON;
		}

		else if (registerFlag == REGISTER_BUTTON) {
			if (register_view->registerButton()) { 
				std::cout << "Send to database" << std::endl;
				std::cout << "User Name: " << register_view->getUsername() << std::endl;
				std::cout << "Pass Name: " << register_view->getPassname() << std::endl;
				isValidRegister = true;
			}
			else {
				registerFlag = CANCEL_BUTTON;
			}
		}
		else if (registerFlag == CANCEL_BUTTON) {
			if (register_view->cancelButton()) {
				break;
			}
			else {
				registerFlag = NAME_INPUT;
			}
		}
		else {
			registerFlag = NAME_INPUT;
		}
	}
	delete register_view;
	closegraph();
	getLoginInfo();
}


