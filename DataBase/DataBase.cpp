#include "DataBase.h"

void DataBase::Menu()
{
	Tree database;

	bool menuWork = true;
	do
	{
		char choice;
		ShowMenu();
		cin >> choice;

		system("cls");

		switch (choice)
		{
		case '0':
			menuWork = false;
			exit(0);
			break;
		case '1':
			AddOffense(database);
			break;
		case '2':
			FindCar(database);
			break;
		case '3':
			MultipleFind(database);
			break;
		case '4':
			database.print();
			break;
		}
	} while (menuWork);
}

void DataBase::ShowMenu()
{
	SetColor(LightCyan);
	cout << "1 - Add offense\n";
	cout << "2 - Find car\n";
	cout << "3 - Show by region or show by region and serias\n";
	cout << "4 - Show all\n";
	cout << "0 - Exit\n\n";

	SetColor(Cyan);
	cout << "Enter your choice: ";
	SetColor(White);
}

void DataBase::AddOffense(Tree& database)
{
	string tempStr;
	Car car;
	bool correct = false;

	SetColor(LightCyan);
	cout << "Enter car number(example AA0000AK [no space]): \n";
	do
	{
		SetColor(Cyan);
		CinRepeir();
		getline(cin, tempStr);

		if (!car.setCarNumber(tempStr))
		{
			correct = false;
			SetColor(Red);
			cout << "Enter car number again: " << endl;
			SetColor(White);
		}
		else
			correct = true;
	} while (!correct);
	SetColor(White);

	Car* find = database.searchByKey(car);

	if (find != nullptr)
		find->addOffense();
	else
	{
		SetColor(Green);
		cout << "New car create! Number set!\n";
		SetColor(White);

		correct = false;
		SetColor(LightCyan);
		cout << "Enter the name of the car owner : ";
		do
		{
			SetColor(Cyan);
			CinRepeir();
			getline(cin, tempStr);
			if (!car.setOwnerName(tempStr))
			{
				correct = false;
				SetColor(Red);
				cout << "Error! Enter name of the car owner again: " << endl;
				SetColor(White);
			}
			else
				correct = true;
		} while (!correct);
		SetColor(White);

		database.insert(car);
		find = database.searchByKey(car);
		find->addOffense();
	}
}

bool DataBase::FindCar(Tree& database)
{
	string tempStr;
	Car car;
	bool correct = false;

	SetColor(LightCyan);
	cout << "Enter car number: ";
	do
	{
		SetColor(Cyan);
		CinRepeir();
		getline(cin, tempStr);
		if (!car.setCarNumber(tempStr))
		{
			correct = false;
			SetColor(Red);
			cout << "Error! Enter car number again: " << endl;
			SetColor(White);
		}
		else
			correct = true;
	} while (!correct);
	SetColor(White);

	Car* find = database.searchByKey(car);

	if (find != nullptr)
	{
		cout << *find << endl;
		return true;
	}

	SetColor(LightPurple);
	cout << "Not found\n";
	SetColor(White);
	return false;
}

void DataBase::MultipleFind(Tree& database)
{
	string key;

	SetColor(LightCyan);
	cout << "Enter region [AA] or region and serias [AABB] no space: ";

	SetColor(Cyan);
	CinRepeir();
	getline(cin, key);
	SetColor(White);

	if (database.getRoot() == nullptr)
	{
		SetColor(LightPurple);
		cout << "Not found\n";
		SetColor(White);
		return;
	}
	database.multipleFind(key);
}
