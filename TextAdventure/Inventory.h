#pragma once
#include <vector>
#include <string>
#include "Item.h"

class Inventory
{
private:
	//Attributes
	std::vector<Item*> m_items;
	int m_collectedQuestItems;

public:
	//Constructors

	Inventory();

	//m_items modifiers

	void addItem(Item* nItem);
	void removeItem(int index);
	void clear();

	
	Item* getItem(int index); //Returns pointer to Item at specified index
	std::vector<Item*>& getItems();
	int getSize();
	bool isEmpty();

	void outputInventory();

	int getQuestItemTotal();
};