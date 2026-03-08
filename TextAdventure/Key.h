#pragma once
#include "Item.h"
class Key :
    public Item
{
private:
	bool isKey;
	string keyID;

public:
	Key();
	Key(string nName, string nDescription, bool nIsKey, string nKeyID);

	string toString() override;
	string getKeyID() override;
};

