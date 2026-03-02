#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string name;
	string description;
	
public:
	Item();
	Item(string nName, string nDescription);

	string getName();
	string getDescription();

	virtual string toString();
};
