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
	virtual int getValue();
	
	virtual void inspectItem();
	virtual string toString();
};
