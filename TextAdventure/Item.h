#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string name;
	int value;

public:
	Item();
	Item(string nName, int nValue);
	string getName();
	int getValue();
	
	virtual void inspectItem();
};
