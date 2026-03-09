#include "Item.h"
#include <string>
#include "Key.h"

Item::Item()
{
	this->name = "An item";
	this->description = "This is an item.";
	this->ingredient = false;
}

Item::Item(string nName, string nDescription, bool isIng)
{
	this->name = nName;
	this->description = nDescription;
	this->ingredient = isIng;
}

bool Item::isIngredient()
{
	return this->ingredient;
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

string Item::getKeyID()
{
	return "";
}

