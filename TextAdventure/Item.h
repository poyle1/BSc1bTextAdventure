#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string name;
	string description;
	bool ingredient;
	
public:
	Item();
	Item(string nName, string nDescription, bool isIng);
	bool isIngredient();

	string getName();
	string getDescription();

	virtual string toString();
	virtual string getKeyID();
};
