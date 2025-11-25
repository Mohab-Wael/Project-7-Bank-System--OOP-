#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{
private:

	enum enCurrencyMenueOptions { eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3, eCurrencyCalculator = 4, eShowMainMenue = 5 };

	static short ReadCurrencyMenueOption()
   	{
		cout << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
		return Choice;
	}


	static void _ShowLCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		cout << "Update Currency Rate Screen will be here...\n";
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		cout << "Currency Calculator Screen will be here...\n";
	}

	static  void _GoBackToCurrencyMenue()
	{
		cout << "\n\nPress any key to go to Currency Menue...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _PerformCurrencyMenueOption(enCurrencyMenueOptions CurrencyMenueOption)
	{
		switch (CurrencyMenueOption)
		{

		case enCurrencyMenueOptions::eListCurrencies:
			system("cls");
			_ShowLCurrenciesListScreen();
			_GoBackToCurrencyMenue();
			break;

		case enCurrencyMenueOptions::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyMenue();
			break;

		case enCurrencyMenueOptions::eUpdateCurrencyRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyMenue();
			break;

		case enCurrencyMenueOptions::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyMenue();
			break;

		case enCurrencyMenueOptions::eShowMainMenue:

			//do nothing here the main screen will handle it :-) ;
			break;
		}
	}

public:

	static void ShowCurrencyExchangeScreen()
	{
		system("cls");

		if(!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		_DrawScreenHeader("\t  Currency Exchange Main Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List of Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		_PerformCurrencyMenueOption((enCurrencyMenueOptions)ReadCurrencyMenueOption());

	}





};

