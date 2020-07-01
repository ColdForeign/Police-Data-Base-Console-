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

void Delict::show() const
{
	cout << this->title << endl;
	cout << this->info << endl;
	cout << "Fine: " << this->fine << endl << endl;
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

size_t Delict::getMaxStrLenght()
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
	
	if (maxLenght == MAX_TITLE_LENGHT)
	{
		size_t thisIter = 0;
		size_t tempSize = 0;
		bool endLine;
		for (size_t i = 0; i < ceil(this->title.length() / maxLenght); i++)
		{
			endLine = false;
			for (size_t j = thisIter; j < this->title.length(); j++)
			{
				if (endLine)
				{
					thisIter = j;
					break;
				}
				if (j >= MIN_INFO_LENGHT)
				{
					if ((this->title[i] == ' '))
					{
						this->title.insert(i, "\n");
						endLine = true;
					}
				}

			}
		}
	}
	

	//if (maxLenght == MAX_TITLE_LENGHT)
	//{
	//	for (size_t i = 0, j = 0; i < this->title.length(); i++, j++)
	//	{
	//		if (j == MAX_TITLE_LENGHT)
	//			j = 0;

	//		if ((j >= MIN_INFO_LENGHT) && (this->title[i] == ' '))
	//			
	//		else
	//			for (size_t k = i; k < length; k++)
	//			{

	//			}
	//	}
	//}

	if (maxLenght % 2 != 0)
		maxLenght++;

	if (maxLenght == MAX_INFO_LENGHT)
		maxLenght += 2;
	else if (maxLenght <= 10)
		maxLenght += 4;
	else if (maxLenght <= 6)
		maxLenght += 10;

	if (maxLenght == MAX_TITLE_LENGHT)
		maxLenght += 4;
	else if (maxLenght <= 10)
		maxLenght += 4;
	else if (maxLenght <= 6)
		maxLenght += 10;
	return maxLenght;
}
