#include "Inventory.h"
#include "Item.h"
#include <vector>
#include <iostream>

//Constructors

Inventory::Inventory()
{
	m_collectedQuestItems = 0;
}

//m_items modifiers

void Inventory::addItem(Item* nItem)
{
	m_items.push_back(nItem);
	if (nItem->isQuestItem())
	{
		m_collectedQuestItems++;
	}
}

void Inventory::removeItem(int index)
{
	if (index < 0 || index >= m_items.size()) {
		return; // Safety check
	}
	m_items.erase(m_items.begin() + index);
}

void Inventory::clear()
{
	m_items.clear();
}

Item* Inventory::getItem(int index)
{
	if (index < 0 || index >= m_items.size()) {
		return nullptr; // Safety check
	}
	return m_items[index];
}

std::vector<Item*>& Inventory::getItems()
{
	return m_items;
}

int Inventory::getSize()
{
	return m_items.size();
}

bool Inventory::isEmpty()
{
	if (m_items.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Inventory::outputInventory()
{
	if (m_items.empty())
	{
		std::cout << "None." << std::endl;
		return;
	}
	for (int i = 0; i < m_items.size(); i++)
	{
		std::cout << m_items[i]->getName() << std::endl;
	}
}

int Inventory::getQuestItemTotal()
{
	return m_collectedQuestItems;
}
