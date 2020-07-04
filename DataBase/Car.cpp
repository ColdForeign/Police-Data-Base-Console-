#include "Car.h"

Car::Car()
{
	this->ownerName = "none";
}

Car::Car(string carNumber, string ownerName)
{
	setCarNumber(carNumber);
	setOwnerName(ownerName);
}

bool Car::setCarNumber(string carNumber)
{
	return this->carNumber.setAll(carNumber);
}

bool Car::setOwnerName(string name)
{
	if (!CheckPeopleName(name))
		return false;

	this->ownerName = name;
	return true;
}

bool Car::setOffenseList(const list<Delict>& offense)
{
	if (offense.empty())
		return false;

	this->delicts = offense;
	return true;
}

string Car::getCarNumber() const
{
	return this->carNumber.getNumber();
}

string Car::getOwnerName() const
{
	return this->ownerName;
}

const list<Delict>& Car::getOffenseListConst() const
{
	return this->delicts;
}

const list<Delict>& Car::getOffenseList()
{
	return this->delicts;
}

const CarNumber& Car::getNumber() const
{
	return this->carNumber;
}

void Car::operator=(const Car& carData)
{
	this->ownerName = carData.getOwnerName();
	this->carNumber = carData.getCarNumber();
	this->delicts = carData.getOffenseListConst();
}

bool Car::operator==(const Car& car) const
{
	return this->carNumber == car.getNumber();
}

bool Car::operator!=(const Car& car) const
{
	return this->carNumber != car.getNumber();
}

bool Car::operator>(const Car& car) const
{
	return this->carNumber > car.getNumber();
}

bool Car::operator<(const Car& car) const
{
	return this->carNumber < car.getNumber();
}

bool Car::operator>=(const Car& car) const
{
	return this->carNumber >= car.getNumber();
}

bool Car::operator<=(const Car& car) const
{
	return this->carNumber <= car.getNumber();
}

bool Car::operator==(string filter) const
{
	return defineFilter(filter, 0);
}

bool Car::operator!=(string filter) const
{
	return defineFilter(filter, 1);
}

bool Car::operator>(string filter) const
{
	return defineFilter(filter, 2);
}

bool Car::operator<(string filter) const
{
	return defineFilter(filter, 3);
}

bool Car::operator>=(string filter) const
{
	return defineFilter(filter, 4);
}

bool Car::operator<=(string filter) const
{
	return defineFilter(filter, 5);
}
void Car::addOffense()
{
	Delict tempDelict;
	string tempText;
	size_t tempNumber;

	bool correct = false;
	SetColor(LightCyan);
	cout << "Enter delict's title: \n";
	do
	{
		SetColor(Cyan);
		CinRepeir();
		getline(cin, tempText);
		if (!tempDelict.setTitle(tempText))
		{
			correct = false;
			SetColor(Red);
			cout << "Invalid number!\n";
			SetColor(White);
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	SetColor(LightCyan);
	cout << "Enter delict's info: \n";
	do
	{
		SetColor(Cyan);
		CinRepeir();
		getline(cin, tempText);
		if (!tempDelict.setInfo(tempText))
		{
			correct = false;
			SetColor(Red);
			cout << "Invalid info!\n";
			SetColor(White);
		}
		else
			correct = true;
	} while (!correct);

	correct = false;
	SetColor(LightCyan);
	cout << "Enter delict's fine: \n";
	do
	{
		SetColor(Cyan);
		CinRepeir();
		cin >> tempNumber;
		if (!tempDelict.setFine(tempNumber))
		{
			correct = false;
			SetColor(Red);
			cout << "Invalid fine!\n";
			SetColor(White);
		}
		else
			correct = true;
	} while (!correct);

	this->delicts.push_back(tempDelict);
}

void Car::SetParameters(CarNumber& carNumber, string filter)
{
	string region;
	string series;

	region += filter[0];
	region += filter[1];
	series += filter[2];
	series += filter[3];

	carNumber.setRegion(region);
	carNumber.setSeries(series);
}

bool Car::defineFilter(string filter, size_t type) const
{
	if (!CheckUpperLetters(filter))
		return false;

	CarNumber temp;

	if (filter.length() == 2)
	{
		temp.setRegion(filter);
		size_t carOrigin = this->carNumber.getRegionPriority();
		size_t CarTemp = temp.getRegionPriority();
		return defineFilterSide(type, carOrigin, CarTemp);
	}
	else if (filter.length() == 4)
	{
		SetParameters(temp, filter);

		size_t carOrigin = this->carNumber.getRegionPriority()
			+ this->carNumber.getSeriesPriority();

		size_t CarTemp = temp.getRegionPriority()
			+ temp.getSeriesPriority();
		return defineFilterSide(type, carOrigin, CarTemp);
	}

	SetColor(Red);
	cout << "Invalid filter!\n";
	SetColor(White);
	return false;
}

bool Car::defineFilterSide(size_t type, size_t origin, size_t side) const
{
	if (type == 0)
		return origin == side;
	if (type == 1)
		return origin != side;
	if (type == 2)
		return origin > side;
	if (type == 3)
		return origin < side;
	if (type == 4)
		return origin >= side;
	if (type == 5)
		return origin <= side;
}

ostream& operator<<(ostream& out, Car& car)
{
	SetColor(LightCyan);
	out << "* Car owner name: " << car.getOwnerName() << endl;
	out << "* Car number: " << car.getCarNumber() << endl;

	cout << endl;

	for (Delict item : car.getOffenseList())
		item.show();

	cout << endl;
	SetColor(Blue);
	cout << "********************\n";

	return out;
}
