#pragma once
#include "Login_View.h"
#include "Register_View.h"
#include "Database.h"


class Login_Controller
{
public:
	Database* mainDatabase; 
	Login_View* loginView; 
	bool isLogin = false; 
	bool isValidRegister = false;

	Login_Controller();
	~Login_Controller();
	void getLoginInfo(); 
	void getRegisterInfo(); 
};



