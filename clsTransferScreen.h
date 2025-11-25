#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"


using namespace std;

class clsTransferScreen : protected clsScreen
{

private:

	static string _ReadAccountNumberFrom()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number to Transfer From: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccoun Number is NOT Found, Enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static string _ReadAccountNumberTo()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number to Transfer To: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccoun Number is NOT Found, Enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0.0;
		cout << "\nEnter Transfer Amount ? ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;
	}

	static void _PrintBalanceClientCard(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "\n_____________________\n";
		cout << "\nFull Name: " << Client.FullName();
		cout << "\nAcc. Number: " << Client.AccountNumber();
		cout << "\nBalance: " << Client.AccountBalance << endl;
		cout << "\n_____________________\n";
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");


		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumberFrom());
		_PrintBalanceClientCard(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumberTo());
		_PrintBalanceClientCard(DestinationClient);

		double Amount = _ReadAmount(SourceClient);
	
		char Answer = 'n';
		cout << "\nAre you sure you want to perform this opreration ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully.\n";
			}
			else
			{
				cout << "\nTransfer Failed.\n";
			}

			_PrintBalanceClientCard(SourceClient);
			_PrintBalanceClientCard(DestinationClient);
		}
	}




};
