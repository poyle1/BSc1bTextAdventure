#include "Item.h"
#include <string>
#include "Key.h"

Item::Item()
{
	this->name = "An item";
	this->description = "This is an item.";
}

Item::Item(string nName, string nDescription)
{
	this->name = nName;
	this->description = nDescription;
}

string Item::getName()
{
	return this->name;
}

string Item::getDescription()
{
	return this->description;
}

string Item::toString()
{
	return this->name + "." + this->description;
}
