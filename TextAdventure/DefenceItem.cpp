#include "DefenceItem.h"

//Default constructor
DefenceItem::DefenceItem()
{
	this->name = "A piece of defencive equipment";
	this->value = 0;
	this->defenceStat = 0;
}

DefenceItem::DefenceItem(string nName, int nValue, int nDamageStat)
{
	this->name = nName;
	this->value = nValue;
	this->defenceStat = nDamageStat;
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
