#include <string>
#include "Key.h"

Key::Key()
{
	this->name = "A key";
	this->description = "This is a key.";
	this->isKey = false;
	this->keyID = "";
}

Key::Key(string nName, string nDescription, bool nIsKey, string nKeyID) : Item(nName, nDescription)
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
