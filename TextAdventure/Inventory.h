#pragma once
#include <vector>

#include "Item.h"

namespace GameObject
{
	class Inventory
	{
	private:
		std::vector<Item*> m_items;
		int m_collectedQuestItems;

	public:
		Inventory();

		void addItem(Item* nItem);
		void removeItem(int index);
		void clear();
		Item* getItem(int index);
		std::vector<Item*>& getInventory();
		int getSize();
		bool isEmpty();

		void outputInventory();
		void outputInventoryWithNumbers();
		void outputQuestItems();

		int getQuestItemTotal();
		bool hasReqQuestItems(int reqAmount) const;

		bool hasItem(std::string nItem);
		int itemAmount(std::string nItem);
		void inventorySearch(std::string nItem);
	};
}