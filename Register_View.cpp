#include "Register_View.h"


void Register_View::Init_Register()
{
	initwindow(600, 600, "Register Account");
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	settextstyle(3, HORIZ_DIR, 3);
	rectangle(150, 50, 500, 110);
	outtextxy(100, 90, "User name:");
	rectangle(150, 150, 500, 210);
	outtextxy(100, 190, "Password:");
	rectangle(150, 250, 500, 310);
	outtextxy(85, 290, "Re-Password:");

	//login button
	settextstyle(3, HORIZ_DIR, 5);

	rectangle(70, 350, 265, 410);
	outtextxy(170, 390, "Register");
	rectangle(290, 350, 490, 410);
	outtextxy(390, 390, "Cancel");
	settextjustify(LEFT_TEXT, LEFT_TEXT);
	settextstyle(BOLD_FONT, HORIZ_DIR, 4);
}

bool Register_View::registerButton()
{
	outtextxy(0, 450, "Register             ");
	int input = getch();
	if (input == TAB_KEY) {
		return false;
	}
	else if (input == ENTER_KEY) {
		if (!isPassCorrect()) {
			outtextxy(0, 500, "Pass not equal        ");
			return false;
		}
		else {
			return true;
		}

	}
}

bool Register_View::cancelButton()
{
	outtextxy(0, 450, "Cancel        ");
	int input = getch();
	if (input == TAB_KEY) {
		return false;
	}
	else if (input == ENTER_KEY) {

		return true;
	}
}

bool Register_View::isPassCorrect()
{
	if (strcmp(repass, this->getPassname()) == 0) {
		return true;
	}
	else {
		return false;
	}

}

void Register_View::repassInput()
{
	outtextxy(0, 450, "Input Re-Password        ");
	while (true) {
		int input = getch();
		if (flag_Repass < 10 && (65 <= input && input <= 90 || 97 <= input && input <= 122 || 48 <= input && input <= 57))
		{
			repass[flag_Repass] = (char)input;
			hidenRePass[flag_Repass] = '*';
			outtextxy(170, 300, hidenRePass);
			flag_Repass++;
			if (flag_Repass == 10) {
				repass[11] == '\0';
			}
		}
		if (input == BACKSPACE_KEY) {
			if (flag_Repass > 0)
			{
				flag_Repass--;
				hidenRePass[flag_Repass] = ' ';
				outtextxy(170, 300, hidenRePass);
				repass[flag_Repass] = NULL;
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
