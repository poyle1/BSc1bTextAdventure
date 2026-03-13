#include <string>
#include "Key.h"
#include "Item.h"

Key::Key()
{
	this->name = "A key";
	this->description = "This is a key.";
	this->isKey = false;
	this->keyID = "";
	this->ingredient = false;
}

Key::Key(string nName, string nDescription, bool nIsKey, string nKeyID) : Item(nName, nDescription, false)
{
	this->isKey = nIsKey;
	this->keyID = nKeyID;
}

string Key::getKeyID()
{
	return this->keyID;
}

string Key::toString()
{
	return this->name + "! Maybe it opens the door to the " + this->keyID;
}
