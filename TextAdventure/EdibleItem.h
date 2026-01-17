#pragma once
#include <iostream>
using namespace std;

#include "Item.h"

class EdibleItem : public Item
{
private:
	int stamRestored;

public:
	//Default constructor
	EdibleItem();
	//Parameterized constructor
	EdibleItem(string nName, int nValue, int nStamVal);

	int getStamRestored();

	void inspectItem() override;
	string toString() override;
};
