#pragma once
#include <iostream>
using namespace std;

class Item
{
private:
	string name;
	int value;

public:
	Item();
	Item(string nName, int nValue);
	string getName();
	int getValue();
};
