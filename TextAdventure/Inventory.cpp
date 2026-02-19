//#include "Inventory.h"
//
//Inventory::Inventory()
//{
//	//empty constructor
//}
//
//void Inventory::addItem(Item& nItem)
//{
//	this->inventoryVec.push_back(&nItem);
//}
//
//void Inventory::removeItem(int index)
//{
//	this->inventoryVec.erase(this->inventoryVec.begin() + index);
//}
//
//int Inventory::getSize()
//{
//	return this->inventoryVec.size();
//}
//
//Item* Inventory::getItem(int index)
//{
//	if (index < 0 || index >= this->inventoryVec.size()) {
//		return nullptr; // Return null pointer for safety check
//	}
//	return this->inventoryVec[index];
//}
//
//int Inventory::getTotalValue()
//{
//	int total = 0;
//	for (int i = 0; i < this->inventoryVec.size(); i++) {
//		total += this->inventoryVec[i]->getValue();
//	}
//	return total;
//}
//
//void Inventory::outputInventory()
//{
//	for (int i = 0; i < this->inventoryVec.size(); i++) {
//		cout << this->inventoryVec[i]->toString() << endl;
//	}
//}
