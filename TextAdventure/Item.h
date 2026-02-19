#pragma once
#include <iostream>
using namespace std;

class Item
{
protected:
	string name;

public:
	Item();
	Item(string nName);

	string getName();
};
