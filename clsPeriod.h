#pragma once
#include <iostream>
#include "clsDate.h"
using namespace std;

class clsPeriod
{
public:
	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	static bool IsOverLapPeriod(clsPeriod Period1, clsPeriod Period2)
	{
		if (clsDate::CompareDates(Period1.StartDate, Period2.EndDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period1.StartDate, Period2.EndDate) == clsDate::enDateCompare::After)
			return false;
		else
		return true;
	}

	bool IsOverLapWith(clsPeriod Period2)
	{
		return IsOverLapPeriod(*this, Period2);
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();

		cout << "Period End: ";
		EndDate.Print();

	}










};

