#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;


	class clsBankClient : public clsPerson
	{
	private:

		enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
		enMode _Mode;

		string _AccountNumber;
		string _PinCode;
		float _AccountBalance;
		bool _MarkedForDelete = false;

		static  clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
		{
			vector <string> vClientDate;
			vClientDate = clsString::Split(Line, Seperator);

			return clsBankClient(enMode::UpdateMode, vClientDate[0], vClientDate[1], vClientDate[2], vClientDate[3], vClientDate[4], vClientDate[5], stod(vClientDate[6]));
		}


		static  string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
		{
			string Line = "";
			Line = Client.FirstName + Seperator;
			Line += Client.LastName + Seperator;
			Line += Client.Email + Seperator;
			Line += Client.Phone + Seperator;
			Line += Client.AccountNumber() + Seperator;
			Line += Client.PinCode + Seperator;
			Line += to_string(Client.AccountBalance);

			return Line;
		}

		static vector <clsBankClient> _LoadClientDataFromFile()
		{
			vector <clsBankClient> vClients;

			fstream MyFile;
			MyFile.open("Clients.txt", ios::in);

			if (MyFile.is_open())
			{
				string Line;

				while (getline(MyFile, Line))
				{
					clsBankClient Client = _ConvertLineToClientObject(Line);
					vClients.push_back(Client);
				}
				MyFile.close();
			}
			return vClients;
		}

		static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
		{
			fstream MyFile;
			MyFile.open("Clients.txt", ios::out | ios::trunc);

			if (MyFile.is_open())
			{
				string DataLine;
				for (clsBankClient& Client : vClients)
				{
					if (Client.MarkedForDelete() == false) {

						DataLine = _ConvertClientObjectToLine(Client);
						MyFile << DataLine << endl;
					}
				}
				MyFile.close();
			}

		}

		void _Update()
		{
			vector <clsBankClient> _vClients;
			_vClients = _LoadClientDataFromFile();

			for (clsBankClient& Client : _vClients)
			{
				if (Client.AccountNumber() == _AccountNumber)
				{
					Client = *this;
					break;
				}
			}

			_SaveClientsDataToFile(_vClients);
		}

		void _AddDataLineToFile(string  stDataLine)
		{
			fstream MyFile;
			MyFile.open("Clients.txt", ios::out | ios::app);

			if (MyFile.is_open())
			{

				MyFile << stDataLine << endl;

				MyFile.close();
			}
		}

		void _AddNew()
		{
			_AddDataLineToFile(_ConvertClientObjectToLine(*this));
		}


		static clsBankClient _GetEmptyClientObject()
		{
			return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
		}

		static void _PrintClientRecordLine(clsBankClient Client)
		{
			cout << "| " << setw(15) << left << Client.AccountNumber();
			cout << "| " << setw(20) << left << Client.FullName();
			cout << "| " << setw(12) << left << Client.Phone;
			cout << "| " << setw(20) << left << Client.Email;
			cout << "| " << setw(10) << left << Client.PinCode;
			cout << "| " << setw(12) << left << fixed << Client.AccountBalance;
		}
		static void _PrintClientRecordBalanceLine(clsBankClient Client)
		{
			cout << "| " << left << setw(15) << Client.AccountNumber();
			cout << "| " << left << setw(40) << Client.FullName();
			cout << "| " << left << setw(12) << fixed << Client.AccountBalance;
		}

		struct stTransferLogRecord;

		static	stTransferLogRecord _ConvertLineToTransferLogRecord(string stDataLine, string Seperator = "#//#")
		{
			vector <string> vString = clsString::Split(stDataLine, Seperator);

			stTransferLogRecord TransferLogRecord;

			TransferLogRecord.DateTime = vString[0];
			TransferLogRecord.SourceAccountNumber = vString[1];
			TransferLogRecord.DestinationAccountNumber = vString[2];
			TransferLogRecord.Amount = stof(vString[3]);
			TransferLogRecord.srcBalanceAfter = stof(vString[4]);
			TransferLogRecord.DestBalaceAfter = stof(vString[5]);
			TransferLogRecord.UserName = vString[6];

			return TransferLogRecord;
		}

		string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
		{
			string TransferLogRecord = "";

			TransferLogRecord = clsDate::GetSystemDateTimeString() + Seperator;
			TransferLogRecord += AccountNumber() + Seperator;
			TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
			TransferLogRecord += to_string(Amount) + Seperator;
			TransferLogRecord += to_string(AccountBalance) + Seperator;
			TransferLogRecord += to_string(DestinationClient.AccountBalance) + Seperator;
			TransferLogRecord += UserName;
			return TransferLogRecord;
		}

		void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
		{
			string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

			fstream MyFile;

			MyFile.open("TransferLog.txt", ios::out | ios::app);
			if (MyFile.is_open())
			{
				MyFile << stDataLine << endl;

				MyFile.close();
			}

		}



	public:

		struct stTransferLogRecord
		{
			string DateTime;
			string SourceAccountNumber;
			string DestinationAccountNumber;
			float Amount;
			float srcBalanceAfter;
			float DestBalaceAfter;
			string UserName;
		};


		clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
			: clsPerson(FirstName, LastName, Email, Phone)
		{
			_Mode = Mode;
			_AccountNumber = AccountNumber;
			_PinCode = PinCode;
			_AccountBalance = AccountBalance;
		}

		bool IsEmpty()
		{
			return (_Mode == enMode::EmptyMode);
		}

		string AccountNumber()
		{
			return _AccountNumber;
		}

		void SetPinCode(string PinCode)
		{
			_PinCode = PinCode;
		}

		string GetPinCode()
		{
			return _PinCode;
		}

		__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

		void SetAccountBalance(float AccountBalance)
		{
			_AccountBalance = AccountBalance;
		}

		float GetAccountBalance()
		{
			return _AccountBalance;
		}

		__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

		bool MarkedForDelete()
		{
			return _MarkedForDelete;
		}

		static clsBankClient Find(string AccountNumber)
		{
			vector <clsBankClient> vClients;

			fstream MyFile;
			MyFile.open("Clients.txt", ios::in);

			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsBankClient Client = _ConvertLineToClientObject(Line);
					if (Client.AccountNumber() == AccountNumber)
					{
						MyFile.close();
						return Client;
					}
					vClients.push_back(Client);
				}
				MyFile.close();
			}
			return _GetEmptyClientObject();
		}

		static clsBankClient Find(string AccountNumber, string PinCode)
		{

			fstream MyFile;
			MyFile.open("Clients.txt", ios::in);//read Mode

			if (MyFile.is_open())
			{
				string Line;
				while (getline(MyFile, Line))
				{
					clsBankClient Client = _ConvertLineToClientObject(Line);
					if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
					{
						MyFile.close();
						return Client;
					}

				}

				MyFile.close();

			}
			return _GetEmptyClientObject();
		}

		static bool IsClientExist(string AccountNumber)
		{
			clsBankClient Client1 = clsBankClient::Find(AccountNumber);
			return (!Client1.IsEmpty());
		}

		enum enSaveResults { svFailedEmptyObject = 0, svSucceded = 1, svFailedAccountNumberExist };

		enSaveResults Save()
		{
			switch (_Mode)
			{
			case enMode::EmptyMode:
				return enSaveResults::svFailedEmptyObject;

			case enMode::UpdateMode:
				_Update();
				return enSaveResults::svSucceded;
				break;

			case enMode::AddNewMode:
				if (clsBankClient::IsClientExist(_AccountNumber))
				{
					return enSaveResults::svFailedAccountNumberExist;
				}
				else
				{
					_AddNew();
					_Mode = enMode::UpdateMode;
					return enSaveResults::svSucceded;
				}
				break;
			}

		}


		static vector <clsBankClient> GetClientsList()
		{
			return _LoadClientDataFromFile();
		}


		static double GetTotalBalances()
		{
			vector <clsBankClient> vClients = clsBankClient::GetClientsList();

			double TotalBalances = 0;

			for (clsBankClient& C : vClients)
			{
				TotalBalances += C.AccountBalance;
			}

			return TotalBalances;
		}

		static clsBankClient GetAddNewClientObject(string AccountNumber)
		{
			return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
		}

		bool Delete()
		{
			vector <clsBankClient> _vClients;
			_vClients = _LoadClientDataFromFile();

			for (clsBankClient& C : _vClients)
			{
				if (C.AccountNumber() == _AccountNumber)
				{
					C._MarkedForDelete = true;
					break;
				}
			}
			_SaveClientsDataToFile(_vClients);

			*this = _GetEmptyClientObject();

			return true;

		}

		void Deposit(double Amount)
		{
			_AccountBalance += Amount;
			Save();
		}

		bool Withdraw(double Amount)
		{
			if (Amount > _AccountBalance)
				return false;
			else
			{
				_AccountBalance -= Amount;
				Save();
				return true;
			}
		}

		bool Transfer(float Amount, clsBankClient& DestinationClient, string UserName)
		{
			if (Amount > AccountBalance)
			{
				return false;
			}

			Withdraw(Amount);
			DestinationClient.Deposit(Amount);
			_RegisterTransferLog(Amount, DestinationClient, UserName);

			return true;
		}

		static vector <stTransferLogRecord> GetTransfersLogList()
		{
			vector <stTransferLogRecord> vTransferLogListRecord;



			fstream MyFile;

			MyFile.open("TransferLog.txt", ios::in);
			if (MyFile.is_open())
			{
				string Line;

				stTransferLogRecord TransferLogRecord;

				while (getline(MyFile, Line))
				{
					TransferLogRecord = _ConvertLineToTransferLogRecord(Line);
					vTransferLogListRecord.push_back(TransferLogRecord);
				}
				MyFile.close();
			}

			return vTransferLogListRecord;

		}

	};

