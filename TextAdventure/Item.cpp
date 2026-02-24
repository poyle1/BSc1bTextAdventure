#include "Item.h"
#include <string>

Item::Item()
{
	this->name = "An item";
	this->description = "This is an item.";
	this->isKey = false;
	this->unlockID = "";
}

Item::Item(string nName, string nDescription, bool nIsKey, string nUnlockID)
{
	this->name = nName;
	this->description = nDescription;
	this->isKey = nIsKey;
	this->unlockID = nUnlockID;
}

string Item::getName()
{
	return this->name;
}

string Item::getDescription()
{
	return this->description;
}