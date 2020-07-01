#pragma once
#include "BinaryTree.h"
#include "Car.h"

class DataBase
{
public:

	static void Menu();

private:

	static void ShowMenu();
	static void AddOffense(Tree& database);
	static bool FindCar(Tree& database);
	static void MultipleFind(Tree& database);
};

