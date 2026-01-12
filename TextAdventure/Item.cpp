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