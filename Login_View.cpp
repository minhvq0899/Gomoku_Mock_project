#include "Login_View.h"

char* Login_View::getUsername()
{
	return username;
}

char* Login_View::getPassname()
{
	return pass;
}



void Login_View::Init_Login()
{
	initwindow(600, 600, "Login");
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(3, HORIZ_DIR, 3);
	rectangle(150, 50, 500, 110);
	outtextxy(100, 90, "User name:");
	rectangle(150, 150, 500, 210);
	outtextxy(100, 190, "Password:");

	//login button
	settextstyle(3, HORIZ_DIR, 5);
	rectangle(100, 250, 245, 310);
	outtextxy(170, 290, "Login");
	rectangle(270, 250, 470, 310);
	outtextxy(370, 290, "Register");
	settextjustify(LEFT_TEXT, LEFT_TEXT);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
}


void Login_View::nameInput()
{
	outtextxy(0, 450, "Input UserName        ");
	while (true) {
		int input = getch();
		if (flag_name < 10 && (65 <= input && input <= 90 || 97 <= input && input <= 122 || 48 <= input && input <= 57))
		{
			username[flag_name] = (char)input;
			outtextxy(170, 100, username);
			flag_name++;
			if (flag_name == 10) {
				username[11] == '\0';
			}
		}
		if (input == BACKSPACE_KEY) {
			if (flag_name > 0) {
				flag_name--;
				username[flag_name] = ' ';
				outtextxy(170, 100, username);
				username[flag_name] = NULL;

			}
			else {
				continue;
			}
		}
		if (input == TAB_KEY) {

			break;
		}
	}
}


void Login_View::passInput()
{
	outtextxy(0, 450, "Input Password        ");

	while (true) {
		int input = getch();
		if (flag_pass < 10 && (65 <= input && input <= 90 || 97 <= input && input <= 122 || 48 <= input && input <= 57))
		{
			pass[flag_pass] = (char)input;
			hidenPass[flag_pass] = '*';
			outtextxy(170, 200, hidenPass);
			flag_pass++;
			if (flag_pass == 10) {
				pass[11] == '\0';
			}
		}
		if (input == BACKSPACE_KEY) {
			if (flag_pass > 0)
			{
				flag_pass--;
				hidenPass[flag_pass] = ' ';
				outtextxy(170, 200, hidenPass);
				pass[flag_pass] = NULL;
			}
			else {
				continue;
			}
		}
		if (input == TAB_KEY) {

			break;
		}

	}
}

void Login_View::error(int)
{
}


bool Login_View::loginInput()
{
	outtextxy(0, 450, "Login         ");
	int input = getch();
	if (input == TAB_KEY) {
		return false;
	}
	else if (input == ENTER_KEY) {
		return true;
	}
}

bool Login_View::registerInput()
{
	outtextxy(0, 450, "Register        ");
	int input = getch();
	if (input == TAB_KEY) {
		return false;
	}
	else if (input == ENTER_KEY) {
		return true;
	}
}
