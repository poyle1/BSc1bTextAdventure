#pragma once
#include <vector>
#include <string>
#include "Item.h"

namespace GameObject
{
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
		Item* getItem(int index);
		std::vector<Item*>& getItems();
		int getSize();
		bool isEmpty();

		void outputInventory();
		void outputInventoryWithNumbers();
		void outputQuestItems();

		int getQuestItemTotal();
		bool hasReqQuestItems(int reqAmount) const;
	};
}