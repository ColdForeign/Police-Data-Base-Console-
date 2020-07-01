#pragma once
#include "Delict.h"
#include "Car.h"
#include "tcolor.h"
#include "CarNumber.h"
#include <list>
using std::cout;
using std::endl;
using std::list;
using std::cin;

struct Node
{
	Car data;

	Node* parent = nullptr;
	Node* left = nullptr;
	Node* right = nullptr;
};

class Tree
{
public:
	Tree();

	void print();
	void print(Node* car);
	void printByFilter(Node* element, string filter);

	Node* searchByKey(string key);
	Car* searchByKey(Car& key);
	void multipleFind(string key);

	Node* getMin(Node* car);
	Node* getMax(Node* car);

	void insert(const Car& newCar);
	void remove(Node* car);
	void deleteAll(Node* car);

	Node* next(Node* car);
	Node* previous(Node* car);
	Node* getRoot();

	~Tree();

private:
	Node* root;
};
