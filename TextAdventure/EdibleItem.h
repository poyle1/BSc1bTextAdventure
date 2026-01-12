#pragma once
#include <iostream>
using namespace std;

#include "Item.h"

class EdibleItem : public Item
{
private:
	int healthRestored;
	int hungerRestored;

public:
	EdibleItem();
	EdibleItem(string nName, int nValue, int nHealthval, int nHungerVal);
	int getHealthRestored();
	int getHungerRestored();
};
