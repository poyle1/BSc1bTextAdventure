#include "DefenceItem.h"
#include <string>

//Default constructor
DefenceItem::DefenceItem()
{
	this->name = "A piece of defencive equipment";
	this->value = 0;
	this->defenceStat = 0;
}

DefenceItem::DefenceItem(string nName, int nValue, int nDefenceStat) : Item(nName, nValue)
{
	this->defenceStat = nDefenceStat;
}

int DefenceItem::getDefenceStat()
{
	return this->defenceStat;
}

void DefenceItem::inspectItem()
{
	cout << "Defence Item Name: " << this->name << endl;
	cout << "Defence Item Value: " << this->value << endl;
	cout << "Defence Item Defence Stat: " << this->defenceStat << endl;
}

string DefenceItem::toString()
{
	return "Defence Item: " + this->name + " is worth " + to_string(this->value) + " gold, and increases defence by " + to_string(this->defenceStat) + ".";
}
