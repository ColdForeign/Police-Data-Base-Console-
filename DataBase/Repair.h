#pragma once
#include <iostream>
using std::cin;

inline void CinRepeir()
{

	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}
