#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsMainScreen.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

private:

	static	void _Login()
	{
		bool LoginFailed = false;
		string Username, Password;
        
		
		do
		{
			if (LoginFailed)
			{
				cout << "\nInvalid UserName/Password!\n";
			}

			cout << "\nEnter Username ? ";
			cin >> Username;

			cout << "\nEnter Password ? ";
			cin >> Password;

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		clsMainScreen::ShowMainMenue();

	}

public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();
	}




};

