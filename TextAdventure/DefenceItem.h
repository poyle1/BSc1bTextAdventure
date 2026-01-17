#pragma once
#include "Item.h"
class DefenceItem : public Item
{
private:
	int defenceStat;
public:
	//Default constructor
	DefenceItem();
	//Parameterized constructor
	DefenceItem(string nName, int nValue, int nDefenceStat);
	
	int getDefenceStat();
	void inspectItem() override;
	string toString() override;
};

