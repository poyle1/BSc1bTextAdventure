#include "EdibleItem.h"
#include <string>


EdibleItem::EdibleItem() : Item()
{
	this->name = "An Edible Item";
	this->value = 0;
	this->healthRestored = 0;
	this->hungerRestored = 0;	
}

EdibleItem::EdibleItem(string nName, int nValue, int nHealthVal, int nHungerVal) : Item(nName, nValue)
{
	this->healthRestored = nHealthVal;
	this->hungerRestored = nHungerVal;
}

int EdibleItem::getHealthRestored()
{
	return this->healthRestored;
}

int EdibleItem::getHungerRestored()
{
	return this->hungerRestored;
}

void EdibleItem::inspectItem()
{
	cout << "Edible Item Name: " << this->name << endl;
	cout << "Edible Item Value: " << this->value << endl;
	if (hungerRestored > 0) {
		cout << "This restores: " << this->hungerRestored << " hunger points." << endl;
	}
	if (healthRestored > 0) {
		cout << "This restores: " << this->healthRestored << " health points." << endl;
	}
}
