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
		void removeItem(int nIndex);
		//void removeItemViaName(const std::string& nName);
		void clear();
		Item* getItemViaIndex(int nIndex) const;
		Item* getItemViaName(const std::string& nName) const;
		std::vector<Item*>& getInventory();
		int getSize() const;
		bool isEmpty() const;

		void outputInventory() const;
		void outputInventoryWithNumbers();
		void outputQuestItems() const;

		int getQuestItemTotal();
		bool hasReqQuestItems(int reqAmount) const;

		bool hasAnItem(const std::string& nItem) const;
		int getItemAmount(const std::string& nItem) const;
	};
}