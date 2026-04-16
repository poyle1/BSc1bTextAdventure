#include "Inventory.h"

#include <vector>
#include <iostream>

#include "Item.h"

namespace GameObject
{
	Inventory::Inventory()
	{
		m_collectedQuestItems = 0;
	}

	void Inventory::addItem(Item* nItem)
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

	Item* Inventory::getItem(int index)
	{
		if (index < 0 || index >= m_items.size()) {
			return nullptr; //Safety check
		}
		return m_items[index];
	}

	std::vector<Item*>& Inventory::getInventory()
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
		for (Item* item : getInventory())
		{
			std::cout << item->getName() << std::endl;
		}
	}

	void Inventory::outputInventoryWithNumbers()
	{
		if (m_items.empty())
		{
			std::cout << "None." << std::endl;
			return;
		}
		for (int i = 0; i < getInventory().size(); i++)
		{
			std::cout << i + 1 << ")" << getInventory()[i]->getName() << std::endl;
		}
	}

	void Inventory::outputQuestItems()
	{
		for (Item* item : getInventory())
		{
			if (item->isQuestItem())
			{
				std::cout << item->getName() << std::endl;
			}
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