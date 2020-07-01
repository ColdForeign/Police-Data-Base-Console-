#pragma once
#include <List>
#include <string>
#include "Checks.h"
#include "CarNumber.h"
#include "Repair.h"
#include "Delict.h"
using std::list;
using std::ostream;


class Car
{
public:
	Car();
	Car(string carNumber, string ownerName);

	bool setCarNumber(string carNumber);
	bool setOwnerName(string name);
	bool setOffenseList(const list<Delict>& offense);

	string getCarNumber() const;
	string getOwnerName() const;
	const list<Delict>& getOffenseList() const;
	const CarNumber& getNumber() const;
	
	void operator = (const Car& carData);
	bool operator == (const Car& carData) const;
	bool operator != (const Car& car) const;
	bool operator > (const Car& car) const;
	bool operator < (const Car& car) const;
	bool operator >= (const Car& car) const;
	bool operator <= (const Car& car) const;

	bool operator == (string filter) const;
	bool operator != (string filter) const;
	bool operator > (string filter) const;
	bool operator < (string filter) const;
	bool operator >= (string filter) const;
	bool operator <= (string filter) const;

	void addOffense();
	friend ostream& operator << (ostream& out, const Car& car);

private:
	static void SetParameters(CarNumber& carNumber, string filter);
	bool defineFilter(string filter, size_t type) const;
	bool defineFilterSide(size_t type, size_t origin, size_t side) const;

	CarNumber carNumber;
	string ownerName;
	list<Delict> delicts;
};

