#include "Item.h"

Item::Item()
{
	this->name = "An item";
	this->value = 0;
}

Item::Item(string nName, int nValue)
{
	this->name = nName;
	this->value = nValue;	
}

string Item::getName()
{
	return this->name;
}

int Item::getValue()
{
	return 0;
}

void Item::inspectItem()
{
	cout << "Item Name: " << this->name << endl;
	cout << "Item Value: " << this->value << endl;
}