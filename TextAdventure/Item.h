#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string name;
	int value;

public:
	//Default constructor
	Item();
	//Parameterized constructor
	Item(string nName, int nValue);

	string getName();
	//virtual function to get value of item
	//can be overridden by derived classes
	//if it wasn't virtual, derived classes would not be able to provide their own implementation
	//and would always use the base class implementation
	virtual int getValue();
	
	virtual void inspectItem();
	virtual string toString();
};
