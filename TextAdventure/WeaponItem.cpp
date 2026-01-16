#include "WeaponItem.h"

//Default constructor
WeaponItem::WeaponItem()
{
	this->name = "A Weapon Item";
	this->value = 0;
	this->damageStat = 0;
}

//Parameterized constructor
WeaponItem::WeaponItem(string nName, int nValue, int nDamageStat)
{
	this->name = nName;
	this->value = nValue;
	this->damageStat = nDamageStat;
}

int WeaponItem::getDamageStat()
{
	return this->damageStat;
}

void WeaponItem::inspectItem()
{
	cout << "Weapon Name: " << this->name << endl;
	cout << "Weapon Value: " << this->value << endl;
	cout << "Weapon Damage Stat: " << this->damageStat << endl;
}
