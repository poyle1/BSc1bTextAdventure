#pragma once
#include "Item.h"
#include <vector>
using namespace std;

class Inventory
{
private:
	//Vector to hold pointers to Item objects
	vector<Item*> inventoryVec;
public:
	Inventory();

	//Item is passed by reference to avoid copying
	void addItem(Item& nItem);
	void removeItem(int index);

	int getSize();

	//Returns pointer to Item at specified index
	Item* getItem(int index);

	int getTotalValue();

	void outputInventory();
};

