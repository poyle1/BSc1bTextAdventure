#include "EdibleItem.h"


EdibleItem::EdibleItem() : Item()
{
	this->name = "An Edible Item";
	this->value = 0;
	this->healthRestored = 0;
	this->hungerRestored = 0;	
}

EdibleItem::EdibleItem(string nName, int nValue, int nHealthval, int nHungerVal) : Item(nName, nValue)
{
	this->healthRestored = nHealthval;
	this->hungerRestored = nHungerVal;
}

int EdibleItem::getHealthRestored()
{
	return this->healthRestored;
}

int EdibleItem::getHungerRestored()
{
	return this->hungerRestored;
}
