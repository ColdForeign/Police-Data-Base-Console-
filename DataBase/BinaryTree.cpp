#include "BinaryTree.h"

Tree::Tree()
{
	this->root = nullptr;
}

void Tree::print()
{
	print(this->root);
}

void Tree::print(Node* car)
{
	if (car == nullptr)
		return;

		print(car->left);
		cout << car->data << endl;
		print(car->right);
}

void Tree::printByFilter(Node* element, string filter)
{
	if (element == nullptr)
		return;

	if (element->data == filter)
		cout << element->data << endl;

	printByFilter(element->left, filter);
	printByFilter(element->right, filter);
}

Node* Tree::searchByKey(string key)
{
	if (this->root == nullptr)
		return nullptr;

	Node* temp = this->root;
	Node* current = this->root;

	do
	{
		temp = current;

		if (current->data == key)
			return temp;
		else if (current->data > key)
			temp = temp->left;
		else
			temp = temp->right;

	} while (temp != nullptr);

	return nullptr;
}

Car* Tree::searchByKey(Car& key)
{
	if (this->root == nullptr)
		return nullptr;

	Node* temp = this->root;
	Node* current = this->root;

	do
	{
		temp = current;

		if (current->data == key)
			return &current->data;
		else if (current->data > key)
			current = current->left;
		else
			current = current->right;

	} while (current != nullptr);

	return nullptr;
}

void Tree::multipleFind(string key)
{
	if (this->root != nullptr)
		printByFilter(this->root, key);
}

Node* Tree::getMin(Node* car)
{
	if (car != nullptr)
		while (car->left != nullptr)
			car = car->left;
	return car;
}

Node* Tree::getMax(Node* car)
{
	if (car != nullptr)
		while (car->right != nullptr)
			car = car->right;
	return car;
}

void Tree::insert(const Car& newCar)
{
	Node* newElement = new Node;
	newElement->data = newCar;

	if (this->root == nullptr)
	{
		this->root = newElement;
		return;
	}

	Node* current = this->root;
	Node* temp = this->root;

	while (current != nullptr)
	{
		temp = current;

		if (newCar == current->data)
			current = current->left;
		else if (newCar > current->data)
			current = current->right;
		else
			current = current->left;

	} 

	newElement->parent = temp;

	if (newCar == temp->data)
		temp->left = newElement;
	else if (newCar > temp->data)
		temp->right = newElement;
	else if (newCar < temp->data)
		temp->left = newElement;
}

void Tree::remove(Node* element)
{
	if (element != nullptr)
	{
		Node* car;
		Node* tempCar;
		if (element->left == nullptr || element->right == nullptr)
			tempCar = element;
		else
			tempCar = next(element);
		
		if (tempCar->left != nullptr)
			car = tempCar->left;
		else
			car = tempCar->right;

		if (car != nullptr)
			car->parent = tempCar->parent;

		if (tempCar->parent == nullptr)
			this->root = car;
		else if (tempCar == tempCar->parent->left)
			tempCar->parent->left = car;
		else
			tempCar->parent->right = car;

		if (tempCar != element)
			element->data = tempCar->data;
		delete tempCar;
	}
}

void Tree::deleteAll(Node* car)
{
	if (car != nullptr)
	{
		Node* tempCar;
		if (car->left == nullptr || car->right ==nullptr)
			tempCar = car;
	}
	else
	{
		while (this->root != nullptr)
			deleteAll(this->root);
	}
}

Node* Tree::next(Node* car)
{
	Node* tempCar = nullptr;

	if (car !=nullptr)
	{
		if (car->right !=nullptr)
			return getMin(car->right);

		tempCar = car->parent;

		while (tempCar !=nullptr && car == tempCar->right)
		{
			car = tempCar;
			tempCar = tempCar->parent;
		}
	}
	return nullptr;
}

Node* Tree::previous(Node* car)
{
	Node* tempCar = nullptr;

	if (car != nullptr)
	{
		if (car->left != nullptr)
			return getMax(car->left);

		tempCar = car->parent;

		while (tempCar != nullptr && car == tempCar->left)
		{
			car = tempCar;
			tempCar = tempCar->parent;
		}
	}
	return nullptr;
}

Node* Tree::getRoot()
{
	return this->root;
}

Tree::~Tree()
{
	remove(this->root);
}



