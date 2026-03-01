#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string name;
	string description;
	bool isKey;
	string keyID;

public:
	Item();
	Item(string nName, string nDescription, bool nIsKey = false, string nKeyID = "");

	string getName();
	string getDescription();
	string getUnlockID();
};
