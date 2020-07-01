#include "Offense.h"

Offense::Offense()
{
	this->title = "none";
	this->info = "none";
	this->fine = 0;
}

Offense::Offense(string title, string info, size_t fine)
{
	setTitle(title);
	setInfo(info);
	setFine(fine);
}

Offense::Offense(const Offense& offense)
{
	this->title = offense.getTitle();
	this->info = offense.getInfo();
	this->fine = offense.getFine();
}

bool Offense::setTitle(string title)
{
	if (CheckTitle(title))
	{
		this->title = title;
		return true;
	}

	return false;
}

bool Offense::setInfo(string info)
{
	if (CheckText(info))
	{
		this->info = info;
		return true;
	}

	return false;
}

bool Offense::setFine(size_t fine)
{
	if (fine >= 0 && fine <= MAX_FINE)
	{
		this->fine = fine;
		return true;
	}

	return false;
}

string Offense::getTitle() const
{
	return this->title;
}

string Offense::getInfo() const
{
	return this->info;
}

size_t Offense::getFine() const
{
	return this->fine;
}