#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string name;
	string description;
	bool isKey;
	string unlockID;

public:
	Item();
	Item(string nName, string nDescription, bool nIsKey = false, string nUnlockID = "");

	string getName();
	string getDescription();
};
