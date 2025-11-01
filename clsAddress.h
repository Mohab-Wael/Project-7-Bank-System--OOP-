#pragma once
#include <iostream>
using namespace std;

class clsAddress 
{
	private:
		string _AddressLine1;
		string _AddressLine2;
		string _POBox;
		string _ZipCode;
	public:
		clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode)
		{
			_AddressLine1 = AddressLine1;
			_AddressLine2 = AddressLine2;
			_POBox = POBox;
			_ZipCode = ZipCode;
		};
		// Copy constructor
		clsAddress(clsAddress& Old_obj)
		{
			_AddressLine1 = Old_obj.AddressLine1();
			_AddressLine2 = Old_obj.AddressLine2();
			_POBox = Old_obj.POBox();
			_ZipCode = Old_obj.ZipCode();
		}

		void SetAddressLine1(string AddressLine1) { _AddressLine1 = AddressLine1; };

		string AddressLine1() { return _AddressLine1; };

		void SetAddressLine2(string AddressLine2) { _AddressLine2 = AddressLine2; };

		string AddressLine2() { return _AddressLine2; };

		void SetPOBox(string POBox) { _POBox = POBox; };

		string POBox() { return _POBox; };

		void SetZipCode(string ZipCode) { _ZipCode = ZipCode; };

		string ZipCode() { return _ZipCode; };

		void Print()
		{
			cout << "\nAddress Details:\n";
			cout << "____________________";
			cout << "\nAddress Line 1 : " << _AddressLine1 << endl;
			cout << "Address Line 2 : " << _AddressLine2 << endl;
			cout << "POBox         : " << _POBox << endl;
			cout << "Zip Code       : " << _ZipCode << endl;
		}
	
};

