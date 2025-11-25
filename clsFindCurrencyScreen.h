#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enFindMenueOptions { eFindByCode = 1, eFindByCountry = 2 };

    static void _PrintCurrencyCard(clsCurrency Currency)
    {
		cout << "\nCurrency Card:\n";
		cout << "____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n____________________________\n";
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "Currency Was NOT Found :-(";
		}

	}

public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t  Find Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Answer = 1;

		cin >> Answer;

		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease enter Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else
		{
			string Country;
			cout << "\nPlease enter Country Name: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}
	}







};

