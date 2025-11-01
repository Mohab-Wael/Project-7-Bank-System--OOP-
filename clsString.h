#pragma once
#pragma once
#include <iostream>
#include<string>
#include <iomanip>
#include<cstdio>
#include <vector>
using namespace std;

class clsString
{
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}


	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return _Value.length();
	}

  static vector <string> Split(string s1, string Delim)
  {
	  vector <string> vString;

	  short pos = 0;
	  string sWord;

	  while ((pos = s1.find(Delim)) != std::string::npos)
	  {
		  sWord = s1.substr(0, pos);
		  if (sWord != "")
		  {
			  vString.push_back(sWord);
		  }
		  s1.erase(0, pos + Delim.length());
	  }
	  if (s1 != "")
	  {
		  vString.push_back(s1);
	  }

	  return vString;
  }

  vector <string> Split(string Delim)
  {
	  return Split(_Value, Delim);
  }

static  string TrimLeft(string s1)
{
	for (short i = 0;i < s1.length();i++)
	{
		if (s1[i] != ' ')
		{
			return s1.substr(i, s1.length() - i);
		}
	}
	return "";
}

   void TrimLeft()
  {
	   _Value = TrimLeft(_Value);
  }

   static string TrimRight(string S1)
   {
	   for (short i = S1.length() - 1;i >= 0;i--)
	   {
		   if (S1[i] != ' ')
			   return S1.substr(0, i + 1);
	   }
	   return "";
   }

   void TrimRight()
   {
	   _Value = TrimRight(_Value);
   }


  static string Trim(string S1)
   {
	   return (TrimLeft(TrimRight(S1)));
   }

  void Trim()
  {
	  _Value = Trim(_Value);
  }

   static  void PrintFirstLetterOfEachWord(string S1)
  {
	  bool isFirstLetter = true;

	  cout << "\nFirst letters of this string: \n";

	  for (short i = 0; i < S1.length(); i++)
	  {
		  if (S1[i] != ' ' && isFirstLetter)
		  {
			  cout << S1[i] << endl;
		  }
		  isFirstLetter = (S1[i] == ' ' ? true : false);
	  }
  }

   void PrintFirstLetterOfEachWord()
   {
	   PrintFirstLetterOfEachWord(_Value);
   }

  static string  UpperFirstLetterOfEachWord(string S1)
   {
	   bool isFirstLetter = true;
	   for (short i = 0; i < S1.length(); i++)
	   { 
		   if (S1[i] != ' ' && isFirstLetter   ) 
		   {
			   S1[i] = toupper(S1[i]);
		   }       
		   isFirstLetter = (S1[i] == ' ' ? true : false);
	   }
	   return S1;
   }

  void  UpperFirstLetterOfEachWord()
  {
	  _Value = UpperFirstLetterOfEachWord(_Value);
  }


  static string  LowerFirstLetterOfEachWord(string S1)
  {
	  bool isFirstLetter = true;
	  for (short i = 0; i < S1.length(); i++)
	  {
		  if (S1[i] != ' ' && isFirstLetter)
		  {
			  S1[i] = tolower(S1[i]);
		  }
		  isFirstLetter = (S1[i] == ' ' ? true : false);
	  }
	  return S1;
  }

  void  LowerFirstLetterOfEachWord()
  {
	  _Value =  LowerFirstLetterOfEachWord(_Value);
  }

 static string  UpperAllString(string S1)
  {
	  for (short i = 0; i < S1.length(); i++)
	  {
		  S1[i] = toupper(S1[i]);
	  } 
	  return S1;
  }
 static string   LowerAllString(string S1)
  {
	  for (short i = 0; i < S1.length(); i++)
	  {
		  S1[i] = tolower(S1[i]);
	  }
	  return S1;
  }

  string  UpperAllString()
  {
	  return UpperAllString(_Value);
  }

  string  LowerAllString()
  {
	  return LowerAllString(_Value);
  }

  static  char  InvertLetterCase(char char1) 
  {
	  return isupper(char1) ? tolower(char1) : toupper(char1);
  }

  static string  InvertAllStringLettersCase(string S1)
  {
	  for (short i = 0; i < S1.length(); i++)
	  {
		  S1[i] = InvertLetterCase(S1[i]); 
	  }
	  return S1; 
  }

  void  InvertAllStringLettersCase()
  {
	  _Value = InvertAllStringLettersCase(_Value);
  }

	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

 static short CountLetters(string S1,  enWhatToCount WhatToCount = enWhatToCount::All)
  {
	  if (WhatToCount == enWhatToCount::All)
	  {
		  return S1.length(); 
	  }
	  short Counter = 0;
	  for (short i = 0; i < S1.length(); i++)
	  {
		  if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			  Counter++;
		  if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i])) 
			  Counter++;
	  } 
	  return Counter;
  }
   
 short CountLetters(enWhatToCount WhatToCount = enWhatToCount::All)
 {
	 return  CountLetters(_Value, WhatToCount);
 }

 static short CountCapitalLetters(string S1)
 {
	 short Counter = 0;
	 for (short i = 0; i < S1.length(); i++)
	 {
		 if (isupper(S1[i]))
			 Counter++;

	 }
	 return Counter;
 }

 short CountCapitalLetters()
 {
	 return CountCapitalLetters(_Value);
 }

 static short CountSmallLetters(string S1)
 {
	 short Counter = 0;
	 for (short i = 0; i < S1.length(); i++)
	 {
		 if (islower(S1[i]))
			 Counter++;
	 }
	 return Counter;
 }




 
static short  CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
 { 
	 short Counter = 0; 
	 for (short i = 0; i < S1.length(); i++)
	 {
		 if (MatchCase)
		 {
			 if (S1[i] == Letter)
				 Counter++; 
		 }
		 else
		 {
			 if (tolower(S1[i]) == tolower(Letter))    
				 Counter++; 
		 }
	 }
	 return Counter;
 }

short  CountSpecificLetter(char Ch1,bool matchCase = true)
{
	return  CountSpecificLetter(_Value, Ch1, matchCase);
}
  
static  bool IsVowel(char Ch1)
{
	Ch1 = tolower(Ch1);
	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}
  
static short  CountVowels(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++) 
	{
		if (IsVowel(S1[i]))  
			Counter++;
	}
	return Counter; 
}

short  CountVowels()
{
	return CountVowels(_Value);
}
 
  static  void PrintVowels(string S1)
{
	cout << "\nVowels in string are: ";
	for (short i = 0; i < S1.length(); i++)
	{ 
		if (IsVowel(S1[i]))  
			cout << S1[i] << "    ";
	}
}

  void PrintVowels()
  {
	  PrintVowels(_Value);
  }

 static  short CountSmallLetter(string s1)
  {
	  short CountSmallLetter = 0;
	  for (short i = 0;i < s1.length();i++)
	  {
		  if (islower(s1[i]))
			  CountSmallLetter++;
	  }
	  return CountSmallLetter;
  }

 short CountSmallLetter()
 {
	 return CountCapitalLetter(_Value);
 }

 static  short CountCapitalLetter(string s1)
  {
	  short CountCapitalLetter = 0;
	  for (short i = 0;i < s1.length();i++)
		  if (isupper(s1[i]))
			  CountCapitalLetter++;

	  return CountCapitalLetter;
  }
   
 static  void PrintEachWordInString(string S1)
 {
	 string delim = " ";
	 cout << "\nYour string wrords are: \n\n";
	 short pos = 0;
	 string sWord;

	 while ((pos = S1.find(delim)) != std::string::npos)
	 {
		 sWord = S1.substr(0, pos);
		 if (sWord != "")
		 {
			 cout << sWord << endl;
		 }
		 S1.erase(0, pos + delim.length());
	 }
		 if (S1 != "")
		 {
			 cout << S1 << endl;
		 }
 }

 void PrintEachWordInString()
 {
	 PrintEachWordInString(_Value);
 }

  static short CountWords(string s1)
  {
	  string delim = " ";
	  short Counter = 0;
	  short pos = 0;
	  string sWord;
	  while ((pos = s1.find(delim)) != std::string::npos)
	  {
		  sWord = s1.substr(0, pos);
		  if (sWord != "")
		  {
			  Counter++;
		  }
		  s1.erase(0, pos + delim.length());

	  }
	  if (s1 != "")
	  {
		  Counter++;
	  }

	  return Counter;
  }

  short CountWords()
  {
	  return CountWords(_Value);
  }


static  string JoinString(vector <string> vString, string Delim)
  {
	  string s1;
	  for (string& s : vString)
	  {
		  s1 = s1 + s + Delim;
	  }
	  return s1.substr(0, s1.length() - Delim.length());
  }

static string JoinString(string arr[], short Length, string Delim)
{
	string s1 = "";
	for (short i = 0;i < Length;i++)
	{
		s1 = s1 + arr[i] + Delim;
	}
	return s1.substr(0, s1.length() - Delim.length());
}

static string ReverseWordsInString(string S1)
{
	vector <string> vString;
	string S2 = "";

	vString = Split(S1, " ");

	vector <string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;

		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1);
	return S2;
}


void ReverseWordsInString()
{
	_Value = ReverseWordsInString(_Value);
}


static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
	vector<string> vString = Split(S1, " ");

	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace) 
			{
				s = sRepalceTo; 
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = sRepalceTo;
			}
		}
	}
	return JoinString(vString, " "); 
}

  string ReplaceWord(string StringToReplace, string sRepalceTo, bool MatchCase = true)
{
	return  ReplaceWord(_Value, StringToReplace, sRepalceTo);
}


 static string RemovePunctuationFromString(string S1)
{
	string S2 = "";
	for (short i = 0;i < S1.length();i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}
	return S2;
}

 string RemovePunctuationFromString()
 {
	 return  RemovePunctuationFromString(_Value);
 }


 static string PrintUpperFirstLetterEachWord(string s1)
 {
	 cout << "Upper First Letters of this string:  \n";
	 bool isFirstLetter = true;
	 for (int i = 0;i < s1.length();i++)
	 {
		 if (s1[i] != ' ' && isFirstLetter)
		 {
			 s1[i] = toupper(s1[i]);
		 }
		 isFirstLetter = (s1[i] == ' ' ? true : false);
	 }
	 return s1;
 }

 string PrintUpperFirstLetterEachWord()
 {
	 return PrintUpperFirstLetterEachWord(_Value);
 }





};
