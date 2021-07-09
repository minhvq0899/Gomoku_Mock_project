#pragma once
#include "Login_View.h"
class Register_View : public Login_View
{
private:
	char* repass;
	int flag_Repass = 0;
	char hidenRePass[10]{ '\0' };
	
public:
	Register_View() {
		repass = new char[11]();
	}
	~Register_View() {
		delete[] repass;
	}
	void Init_Register();
	bool registerButton();
	bool cancelButton();
	bool isPassCorrect();
	void repassInput();
};
