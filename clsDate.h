#pragma once
#pragma warning(disable : 4996) 

#include <iostream>
#include<ctime>
#include<string>
#include <vector>
#include <cctype>
#include <cstdio>
#include "clsString.h"
using namespace std;

class clsDate
{
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		_Year = now->tm_year + 1900;
		_Month = now->tm_mon + 1;
		_Day = now->tm_mday;
	}

	clsDate(string sDate)
	{
		vector <string> vDate = clsString::Split(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DateOrderInYear, short Year)
	{
		clsDate Date1 = GetDateFromDayOrderInYear(DateOrderInYear, Year);

		_Year = Date1._Year;
		_Month = Date1._Month;
		_Day = Date1._Day;
	}

	void SetDay(short Day)
	{
		_Day = Day;
	}

	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}

	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth)) short Month;


	void SetYear(short Year)
	{
		_Year = Year;
	}

	short GetYear()
	{
		return _Year;
	}

	__declspec(property(get = GetYear, put = SetYear)) short Year;

	void Print()
	{
		cout << DateToString() << endl;
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Year, Month, Day;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;

		return clsDate(Day, Month, Year);
	}

	static bool IsValidDate(clsDate Date)
	{
		if (Date.Day < 1 || Date.Day > 31)
			return false;
		if (Date.Month < 1 || Date.Month > 12)
			return false;
		if (Date.Month == 2)
		{
			if (isLeapYear(Date.Year))
			{
				if (Date.Day < 1 || Date.Day > 29)
					return false;
			}
			else
			{
				if (Date.Day < 1 || Date.Day > 28)
					return false;
			}
		}

		short DaysInMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > DaysInMonth)
			return false;

		return true;

	}

	bool IsValid()
	{
		return IsValidDate(*this);
	}

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	string DateToString()
	{
		return DateToString(*this);
	}

	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	bool isLeapYear()
	{
		return isLeapYear(_Year);
	}

	static short NumberOfDaysInYear(short Year)
	{
		return (isLeapYear(Year) ? 366 : 365);
	}

	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{
		return NumberOfDaysInYear(Year) * 24;
	}

	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}

	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}

	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}

	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month > 12)
			return 0;

		int Days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


		return (Month == 2) ? isLeapYear(Year) ? 29 : 28 : Days[Month - 1];
	}

	short NumberOfDaysInAMonth()
	{
		return NumberOfDaysInAMonth(_Month, _Year);
	}

	static int NumberOfHoursInAmonth(short Month, short Year)
	{
		return  NumberOfDaysInAMonth(Month, Year) * 24;
	}

	int NumberOfHoursInAmonth()
	{
		return NumberOfHoursInAmonth(_Month, _Year);
	}

	static int NumberOfMinutesInAmonth(short Month, short Year)
	{
		return NumberOfHoursInAmonth(Month, Year) * 60;
	}

	int NumberOfMinutesInAmonth()
	{
		return NumberOfHoursInAmonth(_Month, _Year) * 60;
	}

	static int NumberOfSecondsOfInAMonth(short Month, short Year)
	{
		return NumberOfMinutesInAmonth(Month, Year) * 60;
	}

	int NumberOfSecondsOfInAMonth()
	{
		return NumberOfMinutesInAmonth(_Month, _Year) * 60;
	}

	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short DayOfWeekOrder()
	{
		return   DayOfWeekOrder(_Day, _Month, _Year);
	}

	static string DayShortName(short Day, short Month, short Year)
	{
		string arrDayName[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayName[DayOfWeekOrder(Day, Month, Year)];
	}

	string DayShortName()
	{
		return DayShortName(_Day, _Month, _Year);
	}

	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan","Feb","Mar","Apr",
			"May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

		return (Months[MonthNumber - 1]);
	}

	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalender(short Month, short Year)
	{
		int NumberOfDays;

		int Current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		printf("\n ____________________%s_________________\n\n", MonthShortName(Month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0;i < Current;i++)
			printf("     ");

		for (int j = 1;j <= NumberOfDays;j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}

		}

		printf("\n  _________________________________\n");
	}

	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}

	static void PrintYearCalender(int Year)
	{
		printf("\n ______________________________________\n\n");
		printf("                   Calender - %d\n", Year);
		printf(" ____________________________________\n");

		for (int i = 1;i <= 12;i++)
		{
			PrintMonthCalender(i, Year);
		}
		return;
	}

	void PrintYearCalender()
	{
		printf("\n ______________________________________\n\n");
		printf("                   Calender - %d\n", _Year);
		printf(" ____________________________________\n");

		for (int i = 1;i <= 12;i++)
		{
			PrintMonthCalender(i, _Year);
		}
		return;
	}

	static short DaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (int i = 1;i <= Month - 1;i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}

	short DaysFromTheBeginingOfTheYear()
	{
		short TotalDays = 0;
		for (int i = 1;i <= _Month - 1;i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, _Year);
		}
		TotalDays += _Day;
		return TotalDays;
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;

		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	void AddDays(short Days)
	{
		short RemainingDays = Days + DaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
		short MonthDays = 0;

		_Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(_Month, _Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;

				if (_Month > 12)
				{
					_Month = 1;
					_Year++;
				}
			}
			else
			{
				_Day = RemainingDays;
				break;
			}
		}
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return ((Date1.Year < Date2.Year) ? true : (Date1.Year == Date2.Year) ?
			(Date1.Month < Date2.Month) ? true : (Date1.Month == Date2.Month) ?
			(Date1.Day < Date2.Day) : false : false);
	}


	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return ((Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) ? true : false : false) : false);
	}

	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
	}

	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	static clsDate AddOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.Month))
			{
				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;
			}
			else
			{
				Date.Day = 1;
				Date.Month++;
			}
		}
		else
		{
			Date.Day++;
		}
		return Date;
	}

	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;


		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = AddOneDay(Date1);
		}
		return  IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}

	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}

	static int CalculateMyAgeInDays(clsDate DateOfBirth)
	{
		return GetDifferenceInDays(DateOfBirth, clsDate::GetSystemDate(), true);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{
		for (int i = 0;i < 7;i++)
			Date = AddOneDay(Date);
		return Date;
	}

	void IncreaseDateByOneWeek()
	{
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 0;i < Weeks;i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}

	void IncreaseDateByXWeeks(short Weeks)
	{
		IncreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short DaysInNewMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);
		if (Date.Day > DaysInNewMonth)
		{
			Date.Day = DaysInNewMonth;
		}
		return Date;
	}

	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 0;i < Days;i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}

	void IncreaseDateByXDays(short Days)
	{
		IncreaseDateByXDays(Days, *this);
	}

	static clsDate  IncreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1;i <= Months;i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(Months, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date.Year++;
		return Date;
	}

	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date.Year += Years;
		return Date;
	}

	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(Years, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		Date.Year += 10;
		return Date;
	}

	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decades, clsDate& Date)
	{
		Date.Year += Decades * 10;
		return Date;
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		Date.Year += 100;
		return Date;
	}

	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		Date.Year += 1000;
		return Date;
	}

	void IncreaseDateByOneMillennium()
	{
		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Day = 31;
				Date.Month = 12;
				Date.Year--;
			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInAMonth(Date.Month, Date.Year);
			}
		}
		else
		{
			Date.Day--;
		}
		return Date;
	}

	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date)
	{
		for (short i = 1;i <= 7;i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByOneWeek()
	{
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1;i <= Weeks;i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}

	void DecreaseDateByXWeeks(short Weeks)
	{
		DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}

		short NumberOfDaysInCurrentMonth = NumberOfDaysInAMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonth(short Months, clsDate& Date)
	{
		for (short i = 1;i <= Months;i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}

	void DecreaseDateByXMonth(short Months)
	{
		DecreaseDateByXMonth(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date.Year--;
		return Date;
	}

	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
	{
		for (short i = 1;i <= Years;i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}

	void DecreaseDateByXYears(short Years)
	{
		DecreaseDateByXYears(Years, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		Date.Year -= 10;
		return Date;
	}

	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decades, clsDate& Date)
	{
		Date.Year -= Decades * 10;
		return Date;
	}

	void DecreaseDateByXDecades(short Decades)
	{
		DecreaseDateByXDecades(Decades, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		Date.Year -= 100;
		return Date;
	}

	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		Date.Year -= 1000;
		return Date;
	}

	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date.Day, Date.Month, Date.Year) == 6;
	}

	bool IsEndOfWeek()
	{
		return  IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);

		return (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}

	bool IsBusinessDay()
	{
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{
		clsDate EndOfMonthDate;
		EndOfMonthDate.Year = Date1.Year;
		EndOfMonthDate.Month = Date1.Month;

		EndOfMonthDate.Day = NumberOfDaysInAMonth(EndOfMonthDate.Month, EndOfMonthDate.Year);


		return GetDifferenceInDays(Date1, EndOfMonthDate, true);
	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Year = Date1.Year;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Day = 31;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);
	}

	short DaysUntilTheEndOfYear()
	{
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateBusnissDays(clsDate DateFrom, clsDate DateTo)
	{
		short Days = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				Days++;

			DateFrom = AddOneDay(DateFrom);
		}
		return Days;
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		return CalculateBusnissDays(DateFrom, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{
		short WeekendCounter = 0;
		for (short i = 1;i <= VacationDays;i++)
		{
			if (IsBusinessDay(DateFrom))
				WeekendCounter++;

			DateFrom = AddOneDay(DateFrom);
		}

		for (short i = 1;i <= WeekendCounter;i++)
			DateFrom = AddOneDay(DateFrom);

		return DateFrom;
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}

	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2)
	{
	  return CompareDates(*this, Date2);
	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Day = now->tm_mday;
		Month = now->tm_mon + 1;
		Year = now->tm_year +1900;

		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second);
	}

};

