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

	Inventory::~Inventory()
	{
		m_items.clear();
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

	void Inventory::removeItem(int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_items.size()) {
			return; //Safety check
		}
		if (m_items[nIndex]->isQuestItem())
		{
			m_collectedQuestItems--;
		}
		m_items.erase(m_items.begin() + nIndex);
	}

	void Inventory::clear()
	{
		m_items.clear();
		m_collectedQuestItems = 0;
	}

	Item* Inventory::getItemViaIndex(int nIndex)
	{
		if (nIndex < 0 || nIndex >= m_items.size()) {
			return nullptr; //Safety check
		}
		return m_items[nIndex];
	}

	Item* Inventory::getItemViaName(const std::string& nName)
	{
		for (Item* item : m_items)
		{
			if (item->getName() == nName)
			{
				return item;
			}
		}
		return nullptr;
	}

	std::vector<Item*>& Inventory::getInventory()
	{
		return m_items;
	}

	int Inventory::getSize() const
	{
		return m_items.size();
	}

	bool Inventory::isEmpty() const
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

	void Inventory::outputInventory() const
	{
		if (m_items.empty())
		{
			std::cout << "None." << std::endl;
			return;
		}
		for (Item* item : m_items)
		{
			std::cout << item->getName() << std::endl;
		}
	}

	void Inventory::outputInventoryWithNumbers() const
	{
		if (m_items.empty())
		{
			std::cout << "None." << std::endl;
			return;
		}
		for (int i = 0; i < m_items.size(); i++)
		{
			std::cout << i + 1 << ")" << m_items[i]->getName() << std::endl;
		}
	}

	void Inventory::outputQuestItems() const
	{
		for (Item* item : m_items)
		{
			if (item->isQuestItem())
			{
				std::cout << item->getName() << std::endl;
			}
		}
	}

	int Inventory::getQuestItemTotal() 
	{
		m_collectedQuestItems = 0;
		for (Item* item : m_items)
		{
			if (item->isQuestItem())
			{
				m_collectedQuestItems ++;
			}
		}
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
	bool Inventory::hasAnItem(const std::string& nItem) const
	{
		for (Item* item : m_items)
		{
			if (item->getName() == nItem)
			{
				return true;
			}
		}
		return false;
	}
	int Inventory::getItemAmount(const std::string& nItem) const
	{
		int amount = 0;
		for (Item* item : m_items)
		{
			if (item->getName() == nItem)
			{
				amount++;
			}
		}
		return amount;
	}
}