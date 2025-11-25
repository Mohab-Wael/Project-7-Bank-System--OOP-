#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogListScreen.h"
using namespace std;


class clsTransactionsScreen :protected clsScreen
{
private:

	enum enTransationMenueOption 
	{
		eDeposit=1,eWithdraw=2,eShowTotalBalance=3,eShowTransferScreen=4,eTransferLogList=5,eShowMainMenue=6
	};

	static short _ReadTransactionsMenueOption()
	{
		cout << setw(37) << left << "" << "\nChoose what do you want to do? [1 to 6]? ";
		short Choice = clsInputValidate::ReadShortNumber();
		return Choice;
	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen()
	{
		clsTotalBalancesSrceen::ShowTotalBalancesScreen();
	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();
	}

	static void _ShowTransferLogListScreen()
	{
		clsTransferLogListScreen::ShowTransferLogListScreen();
	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\nPress any key to go to Transactions Menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}

	static void _PerformTransactionsMenueOption(enTransationMenueOption TransationMenueOption)
	{
		switch (TransationMenueOption)
		{
		case enTransationMenueOption::eDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransationMenueOption::eWithdraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransationMenueOption::eShowTotalBalance:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransationMenueOption::eShowTransferScreen:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransationMenueOption::eTransferLogList:
			system("cls");
			_ShowTransferLogListScreen();
			break;

		//case enTransationMenueOption::eShowMainMenue:
		//	//do nothing here the main screen will handle it :-) ;

		}
	}

public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTranactions))
		{
			return;
		}


		system("cls");

		_DrawScreenHeader("\t  Transactions Screen");


		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformTransactionsMenueOption((enTransationMenueOption)_ReadTransactionsMenueOption());
	}









};

