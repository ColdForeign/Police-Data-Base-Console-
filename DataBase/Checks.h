#pragma once
#include <iostream>
using std::string;

inline bool CheckPeopleName(string name)
{
	size_t tempLenght = 0;
	size_t nameLenght = name.length();
	if (!nameLenght)
		return false;

	for (size_t i = 0; i < nameLenght; i++)
		if ((name[i] >= 'A' && name[i] <= 'Z') || 
			(name[i] >= 'a' && name[i] <= 'z') || 
			name[i] >= ' ')
			tempLenght++;

	if (nameLenght == tempLenght)
		return true;
	else
		return false;
}

inline bool CheckPhoneNumber(string number)
{
	size_t tempLenght = 0;
	size_t lenght = 0;
	size_t numLenght = number.length();
	if (!numLenght)
		return false;

	if (number.find('+') == -1)
		lenght = 12;
	else
		lenght = 13;

	if (numLenght != lenght)
		return false;

	for (size_t i = 0; i < numLenght; i++)
		if ((number[i] >= '0' && number[i] <= '9') ||
			number[i] >= '+')
			tempLenght++;

	if ((numLenght == tempLenght) && numLenght == lenght)
		return true;
	else
		return false;
}

inline bool CheckTitle(string title)
{
	size_t tempLenght = 0;
	size_t titleLenght = title.length();
	if (!titleLenght)
		return false;

	for (size_t i = 0; i < titleLenght; i++)
		if ((title[i] >= 'A' && title[i] <= 'Z') ||
			(title[i] >= 'a' && title[i] <= 'z') ||
			(title[i] >= '0' && title[i] <= '9') ||
			title[i] >= ' ')
			tempLenght++;

	if (titleLenght == tempLenght)
		return true;
	else
		return false;
}

inline bool CheckNumber(string number)
{
	size_t tempLenght = 0;
	size_t numberLenght = number.length();
	if (!numberLenght)
		return false;

	for (size_t i = 0; i < numberLenght; i++)
		if (number[i] >= '0' && number[i] <= '9')
			tempLenght++;

	if (numberLenght == tempLenght)
		return true;
	else
		return false;
}

inline bool CheckUpperLetters(string text)
{
	size_t tempLenght = 0;
	size_t textLenght = text.length();
	if (!textLenght)
		return false;

	for (size_t i = 0; i < textLenght; i++)
		if (text[i] >= 'A' && text[i] <= 'Z')
			tempLenght++;

	if (textLenght == tempLenght)
		return true;
	else
		return false;
}

inline bool CheckLowerLetters(string text)
{
	size_t tempLenght = 0;
	size_t textLenght = text.length();
	if (!textLenght)
		return false;

	for (size_t i = 0; i < textLenght; i++)
		if (text[i] >= 'a' && text[i] <= 'z')
			tempLenght++;

	if (textLenght == tempLenght)
		return true;
	else
		return false;
}