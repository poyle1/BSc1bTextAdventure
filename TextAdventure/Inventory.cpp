#include "Inventory.h"
#include "Item.h"
#include <vector>
#include <iostream>
#include "Common.h"

//Constructors
namespace MilkAndSugar::World
{
	Inventory::Inventory()
	{
		m_collectedQuestItems = 0;
	}

	//m_items modifiers
	void Inventory::addItem(Object::Item* nItem)
	{
		if (nItem == nullptr) {
			return; //Safety check
		}
		m_items.push_back(nItem);
		if (nItem->isQuestItem())
		{
			m_collectedQuestItems++;
		}
	}

	void Inventory::removeItem(int index)
	{
		if (index < 0 || index >= m_items.size()) {
			return; //Safety check
		}
		if (m_items[index]->isQuestItem())
		{
			m_collectedQuestItems--;
		}
		m_items.erase(m_items.begin() + index);
	}

	void Inventory::clear()
	{
		m_items.clear();
		m_collectedQuestItems = 0;
	}

	Object::Item* Inventory::getItem(int index)
	{
		if (index < 0 || index >= m_items.size()) {
			return nullptr; //Safety check
		}
		return m_items[index];
	}

	std::vector<Object::Item*>& Inventory::getItems()
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
		for ( Object::Item* item : getItems())
		{
			std::cout << item->getName() << std::endl;
		}
	}

	int Inventory::getQuestItemTotal()
	{
		return m_collectedQuestItems;
	}

	bool Inventory::hasReqQuestItems(int reqAmount) const
	{
		if (m_collectedQuestItems >= reqAmount)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}