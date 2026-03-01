#include "Item.h"
#include <string>

Item::Item()
{
	this->name = "An item";
	this->description = "This is an item.";
	this->isKey = false;
	this->keyID = "";
}

Item::Item(string nName, string nDescription, bool nIsKey, string nKeyID)
{
	this->name = nName;
	this->description = nDescription;
	this->isKey = nIsKey;
	this->keyID = nKeyID;
}

string Item::getName()
{
	return this->name;
}

string Item::getDescription()
{
	return this->description;
}

string Item::getUnlockID()
{
	return this->keyID;
}
