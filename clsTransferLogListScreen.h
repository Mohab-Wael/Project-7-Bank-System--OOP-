#pragma once
#include <iostream>
#include <vector>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsTransferLogListScreen : protected clsScreen
{

private:

	static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(23) << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(10) << left << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(10) << left << TransferLogRecord.DestBalaceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;
	}

public:

	static void ShowTransferLogListScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransfersLogRecord = clsBankClient::GetTransfersLogList();

		string Title = "\tTansfer Log List Screen";
		string SubTitle = "\t\t(" + to_string(vTransfersLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << "" << left << "\n\t____________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << left<<setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << setw(8) << left << "s.Acct";
		cout << "| " << setw(8) << left << "d.Acct";
		cout << "| " << setw(8) << left << "Amount";
		cout << "| " << setw(10) << left << "s.Balance";
		cout << "| " << setw(10) << left << "d.Balance";
		cout << "| " << setw(8) << left << "User";
		cout << setw(8) << "" << left << "\n\t____________________________________________";
		cout << "___________________________________________________\n" << endl;


		if (vTransfersLogRecord.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Transfer in the system.\n";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord& T : vTransfersLogRecord)
			{
				PrintTransferLogRecordLine(T);

				cout << endl;
			}
		}
 
		cout << setw(8) << "" << left << "\n\t____________________________________________";
		cout << "___________________________________________________\n" << endl;

	}

};
