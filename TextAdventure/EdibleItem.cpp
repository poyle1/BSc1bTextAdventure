#include "EdibleItem.h"
#include <string>


EdibleItem::EdibleItem() : Item()
{
	this->name = "An Edible Item";
	this->value = 0;
	this->stamRestored = 0;
}

EdibleItem::EdibleItem(string nName, int nValue, int nStamVal) : Item(nName, nValue)
{
	this->stamRestored = nStamVal;
}

int EdibleItem::getStamRestored()
{
	return this->stamRestored;
}

void EdibleItem::inspectItem()
{
	cout << "Edible Item Name: " << this->name << endl;
	cout << "Edible Item Value: " << this->value << endl;
	cout << "Stamina Restored: " << this->stamRestored << endl;
}

string EdibleItem::toString()
{
	return "Item: " + this->name + " is worth " + to_string(this->value) + " gold, and restores " + to_string(this->stamRestored) + " stamina.";
}
