#pragma once
#include "Checks.h"
using std::cout;
using std::endl;

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
	
	void show() const;

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
	};
	void setStandart();
	size_t getMaxStrLenght();

	void alignText(string text, size_t maxLenght, size_t min);
	const size_t MAX_FINE = 51000;
	string title;
	string info;
	size_t fine;
	

};