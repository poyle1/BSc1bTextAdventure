#pragma once
#include "Item.h"
class WeaponItem : public Item
{
private: 
	int damageStat;
public:
	WeaponItem();
	//WeaponItem(string nName, int nValue, int nDamageStat);

	int getDamageStat();

	//void inspectItem() override;
	//string toString() override;

};

