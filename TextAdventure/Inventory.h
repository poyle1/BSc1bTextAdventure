#pragma once
#include <vector>
#include <string>
#include "Item.h"

namespace MilkAndSugar::World
{
	class Inventory
	{
	private:
		//Attributes
		std::vector<MilkAndSugar::Object::Item*> m_items;
		int m_collectedQuestItems;

	public:
		//Constructors
		Inventory();

		//m_items modifiers
		void addItem(MilkAndSugar::Object::Item* nItem);
		void removeItem(int index);
		void clear();
		MilkAndSugar::Object::Item* getItem(int index);
		std::vector<MilkAndSugar::Object::Item*>& getItems();
		int getSize();
		bool isEmpty();

		void outputInventory();
		void outputInventoryWithNumbers();
		void outputQuestItems();

		int getQuestItemTotal();
		bool hasReqQuestItems(int reqAmount) const;
	};
}