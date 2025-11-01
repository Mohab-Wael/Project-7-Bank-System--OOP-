#pragma once
#include <iostream>
#include "clsPerson.h"

using namespace std;


class clsEmployee : public clsPerson
{

	
	private:
		string _Title;
		string _Department;
		float _Salary;
	public:

		clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, float Salary)
			: clsPerson(ID, FirstName, LastName, Email, Phone)
		{
			_Title = Title;
			_Department = Department;
			_Salary = Salary;
		}

		void SetTitle(string Title)
		{
			_Title = Title;
		}
		string Title()
		{
			return _Title;
		}
		void SetDepartment(string Department)
		{
			_Department = Department;
		}
		string Department()
		{
			return _Department;
		}
		void SetSalary(float Salary)
		{
			_Salary = Salary;
		}
		float Salary()
		{
			return _Salary;
		}
		void Print()
		{
			cout << "\nInfo:\n\n";
			cout << "_____________________________\n";
			cout << "ID          : " << ID();
			cout << "\nFirst Name  : " << FirstName();
			cout << "\nLast Name   : " << LastName();
			cout << "\nFull Name   : " << FullName();
			cout << "\nEmail       : " << Email();
			cout << "\nPhone       : " << Phone();
			cout << "\nTitle       : " << _Title;
			cout << "\nDepartment  : " << _Department;
			cout << "\nSalary      : " << _Salary;
			cout << "\n_____________________________\n";
		}
	
};

