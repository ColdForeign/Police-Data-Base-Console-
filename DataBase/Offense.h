#pragma once
#include "Check.h"

class Offense
{
public:
	Offense();
	Offense(string title, string info, size_t fine);
	Offense(const Offense& offense);

	/*setters*/

	bool setTitle(string title);
	bool setInfo(string info);
	bool setFine(size_t fine);

	/*getters*/

	string getTitle() const;
	string getInfo() const;
	size_t getFine() const;

private:
	const size_t MAX_FINE = 10000;
	string title;
	string info;
	size_t fine;

};