#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsMainScreen.h"
#include <fstream>

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:

	static	bool _Login()
	{
		bool LoginFailed = false;
		string Username, Password;
		short LoginFailedCount = 0;
		
		do
		{
			if (LoginFailed)
			{
				LoginFailedCount++;
				cout << "\nInvalid UserName/Password!\n";
				cout << "You have " << (3-LoginFailedCount) << " Trails to login.\n";
			}

			if (LoginFailedCount == 3)
			{
				cout << "\n\nYou are Locked after 3 failed trails.\n";
				return false;
			}

			cout << "\nEnter Username ? ";
			cin >> Username;

			cout << "\nEnter Password ? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);
   
		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		return true;
	}




public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
	}




};

