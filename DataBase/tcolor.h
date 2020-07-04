#pragma once
#include <windows.h>

namespace ConsoleColors
{
	enum ConsoleColor
	{
		Black = 0,
		Blue,
		Green,
		Cyan,
		Red,
		Purple,
		Brown,
		LightGray,
		DarkGray,
		LightBlue,
		LightGreen,
		LightCyan,
		LightRed,
		LightPurple,
		Yellow,
		White = 15
	};

	inline void SetColor(ConsoleColor color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, WORD(color));
	}

	inline void SetColor(size_t color)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, WORD(color));
	}
}
