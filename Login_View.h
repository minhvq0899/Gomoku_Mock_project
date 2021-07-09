#pragma once
#include "graphics.h"



#define NAME_INPUT 1
#define PASS_INPUT 2
#define LOGIN_BUTTON 3
#define REGISTER_BUTTON 4
#define CANCEL_BUTTON 5
#define REPASS_INPUT 6

#define BACKSPACE_KEY 8
#define TAB_KEY 9
#define ENTER_KEY 13
#define ECS_KEY 27


#define INVALID_PASS_USERNAME 100
#define EXIST_PLAYER 101

class Login_View
{
private:
	char* username;
	char* pass;
	char hidenPass[10]{ '\0' };
	int flag_name = 0;
	int flag_pass = 0;
public:
	Login_View() {
		username = new char[11]();
		pass = new char[11]();
	}
	virtual ~Login_View() {
		delete[] username;
		delete[] pass;
	}

	char* getUsername();
	char* getPassname();
	


	void Init_Login();
	void nameInput();
	void passInput();
	bool loginInput();
	bool registerInput();
	void error(int);
};

