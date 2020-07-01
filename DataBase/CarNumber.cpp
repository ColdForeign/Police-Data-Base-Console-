#include "CarNumber.h"

CarNumber::CarNumber()
{
	this->region = "AA";
	this->number = "0000";
	this->series = "AK";
}

CarNumber::CarNumber(string region, string number, string series)
{
	if (!setAll(region, number, series))
	{
		SetColor(Red);
		cout << "Setted standart data!\n";
		SetColor(White);
		return;
	}
}

CarNumber::CarNumber(string number)
{
	if (!setAll(number))
	{
		SetColor(Red);
		cout << "Setted standart data!\n";
		SetColor(White);
		return;
	}
}

bool CarNumber::setRegion(string region)
{
	if (region.length() != REGION_LENGHT)
		return false;

	if (CheckUpperLetters(region))
	{
		this->region = region;
		return true;
	}

	return false;
}

bool CarNumber::setNumber(string number)
{
	if (number.length() != NUM_LENGHT)
		return false;

	if (CheckNumber(number))
	{
		this->number = number;
		return true;
	}

	return false;
}

bool CarNumber::setSeries(string series)
{
	if (series.length() != SERIES_LENGHT)
		return false;

	if (CheckUpperLetters(series))
	{
		this->series = series;
		return true;
	}

	return false;
}

bool CarNumber::setAll(string region, string number, string series)
{
	bool correct = false;
	if (setRegion(region))
	{
		correct = true;
		if (setNumber(number))
		{
			correct = true;
			if (!setSeries(series))
			{
				correct = false;
				setStandart();
				SetColor(Red);
				cout << "Invalid number series value!\n";
				SetColor(White);
			}
			else
				correct = true;
		}
		else
		{
			correct = false;
			setStandart();
			SetColor(Red);
			cout << "Invalid registration number!\n";
			SetColor(White);
		}
	}
	else
	{
		correct = false;
		setStandart();
		SetColor(Red);
		cout << "Invalid region value!\n";
		SetColor(White);
	}
	return correct;
}

bool CarNumber::setAll(string number)
{
	if (number.length() != this->LENGHT)
	{
		SetColor(Red);
		cout << "Invalid number!\n";
		SetColor(White);
		return false;
	}

	string tempRegion;
	string tempNumber;
	string tempLast;

	tempRegion += number[0]; tempRegion += number[1];

	tempNumber += number[2]; tempNumber += number[3];
	tempNumber += number[4]; tempNumber += number[5];

	tempLast += number[6]; tempLast += number[7];

	if (!setAll(tempRegion, tempNumber, tempLast))
	{
		SetColor(Red);
		cout << "Setted standart data!\n";
		SetColor(White);
		return false;
	}

	return true;
}

string CarNumber::getRegion() const
{
	return this->region;
}

string CarNumber::getRegistNumber() const
{
	return this->number;
}

string CarNumber::getSeries() const
{
	return this->series;
}

string CarNumber::getNumber() const
{
	return this->region + this->number + this->series;
}

void CarNumber::operator=(const CarNumber& carNumber)
{
	this->region = carNumber.getRegion();
	this->number = carNumber.getRegistNumber();
	this->series = carNumber.getSeries();
}

bool CarNumber::operator==(const CarNumber& carNumber) const
{
	return (this->getPriority() == carNumber.getPriority());
}

bool CarNumber::operator!=(const CarNumber& carNumber) const
{
	return (this->getPriority() != carNumber.getPriority());
}

bool CarNumber::operator>(const CarNumber& carNumber) const
{
	return (this->getPriority() > carNumber.getPriority());
}

bool CarNumber::operator<(const CarNumber& carNumber) const
{
	return (this->getPriority() < carNumber.getPriority());
}

bool CarNumber::operator>=(const CarNumber& carNumber) const
{
	return (this->getPriority() >= carNumber.getPriority());
}

bool CarNumber::operator<=(const CarNumber& carNumber) const
{
	return (this->getPriority() <= carNumber.getPriority());
}

bool CarNumber::search(string key)
{
	string number = getNumber();
	if (number.find(key) != -1)
		return true;
	else
		return false;
}

void CarNumber::setStandart()
{
	this->region = "AA";
	this->number = "0000";
	this->series = "AK";
}

size_t CarNumber::getPriority() const
{
	size_t priority;
	size_t priorityNumber = 0;
	priority = (this->region[0] - 65) + (this->region[1] - 65);

	for (size_t i = 2, j = 10; i != -1; i--, j *= 10)
		priorityNumber += (this->number[i] - 48) * j;

	priorityNumber += (this->number[3] - 48);

	priority += priorityNumber;
	priority += (this->series[0] - 65) + (this->series[1] - 65);
	return priority;
}

size_t CarNumber::getRegionPriority() const
{
	return (this->region[0] - 65) + (this->region[1] - 65);
}

size_t CarNumber::getSeriesPriority() const
{
	return (this->series[0] - 65) + (this->series[1] - 65);
}
