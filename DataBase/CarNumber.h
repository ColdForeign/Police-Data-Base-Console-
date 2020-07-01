#pragma once
#include <iostream>
#include "tcolor.h"
#include "Checks.h"
using std::string;
using std::cout;
using namespace ConsoleColors;

class CarNumber
{
public:
    CarNumber();
    CarNumber(string region, string number, string series);
    CarNumber(string number);

    bool setRegion(string region);
    bool setNumber(string number);
    bool setSeries(string series);
    bool setAll(string region, string number, string series);

    bool setAll(string number);
    string getRegion() const;
    string getRegistNumber() const;
    string getSeries() const;
    string getNumber() const;

    void operator = (const CarNumber& carNumber);
    bool operator == (const CarNumber& carNumber) const;
    bool operator != (const CarNumber& carNumber) const;
    bool operator > (const CarNumber& carNumber) const;
    bool operator < (const CarNumber& carNumber) const;
    bool operator >= (const CarNumber& carNumber) const;
    bool operator <= (const CarNumber& carNumber) const;

    size_t getPriority() const;
    size_t getRegionPriority() const;
    size_t getSeriesPriority() const;

    bool search(string key);

private:
    void setStandart();

    const size_t LENGHT = 8;
    const size_t REGION_LENGHT = 2;
    const size_t SERIES_LENGHT = 2;
    const size_t NUM_LENGHT = 4;

    string region;
    string number;
    string series;
};
