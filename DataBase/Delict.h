#pragma once
#include "Checks.h"
#include "tcolor.h"
#include <vector>
using namespace ConsoleColors;

using std::cout;
using std::endl;
using std::vector;

class Delict
{
public:
	Delict();
	Delict(string title, string info, size_t fine);
	Delict(const Delict& offense);

	bool setTitle(string title);
	bool setInfo(string info);
	bool setFine(size_t fine);

	string getTitle() const;
	string getInfo() const;
	size_t getFine() const;
	void showTitle(ConsoleColor textColor = LightCyan, ConsoleColor borderColor = Purple);
	void showInfo(ConsoleColor textColor = LightCyan, ConsoleColor borderColor = Purple);
	void showFine(ConsoleColor textColor = LightCyan, ConsoleColor borderColor = Purple);
	void show();

	void operator = (const Delict& delict);
private:
	enum Limits
	{
		MIN_TITLE_LENGHT = 10,
		MAX_TITLE_LENGHT = 16,
		MAX_TITLE_STR_QANTITY = 2,

		MIN_INFO_LENGHT = 12,
		MAX_INFO_LENGHT = 18,

		MIN_INFO_STR_QUANTITY = 3,
		MAX_INFO_STR_QUANTITY = 10,

		MAX_STR_LENGHT = 22,

	};
	void setStandart();
	size_t getMaxStrLenght() const;
	void alignText(vector<string>& tempText, string text, size_t min, size_t max);
	void ShowLine(const char symbol, size_t size, ConsoleColor color);
	size_t getThisBoxLenght() const;
	void ShowSpace(string text);

	const size_t MAX_FINE = 51000;
	string title;
	string info;
	size_t fine;
	vector<string> titleAlign;
	vector<string> infoAlign;
};
