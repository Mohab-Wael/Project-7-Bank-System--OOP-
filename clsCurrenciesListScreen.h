#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"

using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{
private:

	static void _PrintCurrencyRecord(clsCurrency Currency)
	{
		cout << setw(8) << left <<  "" << "| " << setw(30) << left  << Currency.Country();
		cout << "| " << setw(8)  << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << fixed << Currency.Rate();
	}

public:

	static void ShowCurrenciesListScreen()
	{

		vector <clsCurrency> vCurrencies = clsCurrency::GetAllCurrenciesList();


		string Title = "\t  Currencies List Screen";
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title,SubTitle);

		cout << setw(8) << left << "" << "\n\t____________________________________________________________";
		cout << "______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << setw(8)  << left << "Code";
		cout << "| " << setw(45) << left << "Name";
		cout << "| " << setw(10) << left << "Rate/(1$)";

		cout << setw(8) << left << "" << "\n\t____________________________________________________________";
		cout << "______________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << setw(8) << left << "" << "\t\tNo Currencies Available In The System!\n";
		}
		else
		{
			for (clsCurrency& C : vCurrencies)
			{
				_PrintCurrencyRecord(C);
				cout << endl;
			}
		}

		cout << setw(8) << left << "" << "\n\t____________________________________________________________";
		cout << "______________________________________________\n" << endl;

	}

};

