#include "Delict.h"

Delict::Delict()
{
	this->title = "";
	this->info = "";
	this->fine = 0;
}

Delict::Delict(string title, string info, size_t fine)
{
	if (setTitle(title))
	{
		if (setInfo(info))
		{
			if (!setFine(fine))
			{
				setStandart();
				cout << "Invalid fine for delict!\n";
			}
		}
		else
		{
			setStandart();
			cout << "Invalid info about delict!\n";
		}
	}
	else
	{
		setStandart();
		cout << "Invalid delict title!\n";
	}

}

Delict::Delict(const Delict& offense)
{
	this->title = offense.getTitle();
	this->info = offense.getInfo();
	this->fine = offense.getFine();
}

bool Delict::setTitle(string title)
{
	if (CheckTitle(title))
	{
		this->title = title;
		return true;
	}

	return false;
}

bool Delict::setInfo(string info)
{
	if (!info.empty())
	{
		this->info = info;
		return true;
	}

	return false;
}

bool Delict::setFine(size_t fine)
{
	if (fine >= 0 && fine <= MAX_FINE)
	{
		this->fine = fine;
		return true;
	}

	return false;
}

string Delict::getTitle() const
{
	return this->title;
}

string Delict::getInfo() const
{
	return this->info;
}

size_t Delict::getFine() const
{
	return this->fine;
}

void Delict::showTitle(ConsoleColor textColor, ConsoleColor borderColor)
{
	size_t boxLenght = getThisBoxLenght();

	ShowLine('*', boxLenght, borderColor);
	SetColor(borderColor);
	cout << "* ";

	ShowSpace(this->title);
	SetColor(textColor);
	cout << this->title;
	ShowSpace(this->title);

	SetColor(borderColor);
	cout << " *\n";
	ShowLine('*', boxLenght, borderColor);
}

void Delict::showInfo(ConsoleColor textColor, ConsoleColor borderColor)
{
	size_t maxTextLenght = MAX_INFO_LENGHT;
	size_t quantitySpace;
	for (size_t i = 0; i < this->infoAlign.size(); i++)
	{
		quantitySpace = MAX_INFO_LENGHT - this->infoAlign[i].size();
		SetColor(borderColor);
		cout << "* ";
		SetColor(textColor);
		cout << this->infoAlign[i];
		for (size_t i = 0; i < quantitySpace; i++)
			cout << ' ';
		SetColor(borderColor);
		cout << " *\n";

	}
}

void Delict::showFine(ConsoleColor textColor, ConsoleColor borderColor)
{
	size_t boxLenght = getThisBoxLenght();
	size_t chargedPercent = size_t(this->fine / float(this->MAX_FINE / 100.0));
	size_t fineLenght = ((this->fine == 0) ? 1
		: int(log10(this->fine) + 1)) + strlen("Fine: ");

	ShowLine('*', boxLenght, borderColor);
	SetColor(borderColor);
	cout << "* ";

	size_t quantitySpace = boxLenght - 4 - fineLenght;
	for (size_t i = 0; i < quantitySpace; i++)
		cout << ' ';

	SetColor(textColor);
	cout << "Fine: ";

	if (chargedPercent <= 20)
		SetColor(LightGreen);
	else if ((chargedPercent > 20) && (chargedPercent <= 40))
		SetColor(Green);
	else if ((chargedPercent > 40) && (chargedPercent <= 60))
		SetColor(Yellow);
	else if ((chargedPercent > 60) && (chargedPercent <= 80))
		SetColor(LightRed);
	else if ((chargedPercent > 80) && (chargedPercent <= 100))
		SetColor(Red);

	cout << this->fine;

	SetColor(borderColor);
	cout << " *\n";
	ShowLine('*', boxLenght, borderColor);
}

void Delict::show()
{
	alignText(this->titleAlign, this->title, MIN_TITLE_LENGHT, MAX_TITLE_LENGHT);
	alignText(this->infoAlign, this->info, MIN_INFO_LENGHT, MAX_INFO_LENGHT);

	showTitle();
	showInfo();
	showFine();
}

void Delict::operator=(const Delict& delict)
{
	this->title = delict.getTitle();
	this->info = delict.getInfo();
	this->fine = delict.getFine();
}

void Delict::setStandart()
{
	this->title = "";
	this->info = "";
	this->fine = 0;
}

size_t Delict::getMaxStrLenght() const
{
	size_t fineLenght = ((this->fine == 0) ? 1
		: int(log10(this->fine) + 1)) + strlen("Fine: ");

	size_t maxLenght = fineLenght;
	if (maxLenght < this->title.length())
	{
		if (this->title.length() <= MAX_TITLE_LENGHT)
			maxLenght = this->title.length();
		else
			maxLenght = MAX_TITLE_LENGHT;
	}

	if (maxLenght < this->info.length())
	{
		if (this->info.size() <= MAX_INFO_LENGHT)
			maxLenght < this->info.length();
		else
			maxLenght = MAX_INFO_LENGHT;
	}

	if (maxLenght % 2 != 0)
		maxLenght++;

	return maxLenght;
}

void Delict::alignText(vector<string>& tempText, string text, size_t min, size_t max)
{
	size_t tempMin = 0;
	size_t thisIter = 0;
	size_t tempIter = 0;
	bool endLine;
	string tempStr = "";
	endLine = false;
	for (size_t i = 0, j = 0; i < text.length(); i++, j++)
	{
		tempStr.push_back(text[i]);
		if (tempStr[tempStr.size() - 1] == text[text.size() - 1])
			tempText.push_back(tempStr);
		if (endLine)
			thisIter = 0;
		if (thisIter >= min - tempMin)
		{
			if (text[i] == ' ')
			{
				tempIter = i + 1;
				tempMin = 0;
				j = 0;
				tempText.push_back(tempStr);
				tempStr.clear();
				endLine = true;
			}
		}
		else if ((thisIter == max) && !endLine)
		{
			j = 0;
			tempStr.clear();
			i = tempIter;
			tempMin++;
		}
		else
			endLine = false;
		thisIter++;
	}
}

void Delict::ShowLine(const char symbol, size_t size, ConsoleColor color)
{
	if (size > 120)
		return;
	for (size_t i = 0; i < size; i++)
	{
		SetColor(color);
		cout << symbol;
		SetColor(White);
	}
	cout << endl;
}

size_t Delict::getThisBoxLenght() const
{
	size_t maxStrSize = getMaxStrLenght();

	if (MAX_TITLE_LENGHT == maxStrSize)
		maxStrSize += (MAX_STR_LENGHT - MAX_TITLE_LENGHT);

	if (MAX_INFO_LENGHT == maxStrSize)
		maxStrSize += (MAX_STR_LENGHT - MAX_INFO_LENGHT);

	return maxStrSize;
}

void Delict::ShowSpace(string text)
{
	size_t boxLenght = getThisBoxLenght();
	size_t spaceQuantity;
	spaceQuantity = boxLenght - text.size();

	spaceQuantity -= 4;
	spaceQuantity /= 2;

	if (text.size() % 2 != 0 && spaceQuantity % 2 != 0)
		spaceQuantity++;

	for (size_t i = 0; i < spaceQuantity; i++)
		cout << ' ';
}
