#include "Item.h"
#include <string>

Item::Item()
{
	this->name = "An item";
}

Item::Item(string nName)
{
	this->name = nName;
}

string Item::getName()
{
	return this->name;
}
