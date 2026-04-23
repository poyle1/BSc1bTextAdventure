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
		~Inventory();

		void addItem(Item* nItem);
		void removeItem(int nIndex);
		void clear();
		Item* getItemViaIndex(int nIndex);
		Item* getItemViaName(const std::string& nName);
		std::vector<Item*>& getInventory();
		int getSize() const;
		bool isEmpty() const;

		void outputInventory() const;
		void outputInventoryWithNumbers() const;
		void outputQuestItems() const;

		int getQuestItemTotal() ;
		bool hasReqQuestItems(int reqAmount) const;

		bool hasAnItem(const std::string& nItem) const;
		int getItemAmount(const std::string& nItem) const;
	};
}