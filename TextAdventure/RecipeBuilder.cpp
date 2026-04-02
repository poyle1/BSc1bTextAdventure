#include "RecipeBuilder.h"
#include "Common.h"
#include <stack>
#include <iostream>
#include "Utility"
#include "Utility.h"

namespace MilkAndSugar::Core
{
	RecipeBuilder::RecipeBuilder()
	{

	}
	bool MilkAndSugar::Core::RecipeBuilder::testQuest(Object::Player& nPlayer)
	{
		std::stack<Object::Item*> winningStack;
		std::stack<Object::Item*> playerStack;
		std::vector<Object::Item*> tempStack;

		Object::Item mug("Mug1", "1", true);
		Object::Item teabag("Tea bag2", "2", true);
		Object::Item sugar("Sugar3", "3", true);
		Object::Item water("Water4", "4", true);
		Object::Item milk("Milk5", "5", true);
		winningStack.push(&mug);
		winningStack.push(&teabag);
		winningStack.push(&sugar);
		winningStack.push(&water);
		winningStack.push(&milk);

		bool eventCompleted = false;
		int maxValidInput = nPlayer.getInventory().getSize();

		while (!eventCompleted)
		{
			//Stack Info
			std::cout << "You have: " << std::endl;
			nPlayer.getInventory().outputInventory();

			if (!tempStack.empty())
			{
				std::cout << "Current Stack:" << std::endl;
				for (int i = 0; i < tempStack.size(); i++)
				{
					std::cout << "-" << tempStack.at(i)->getName() << std::endl;
				}
			}
			//Player Input
			std::cout << std::endl;
			std::cout << "Enter the item you want to add to the stack: ";
			std::cout << std::endl;
			int stackInput = UI::getValidIntInput(1, nPlayer.getInventory().getSize());
			std::cout << std::endl;

			//3 . Update Game State
			Object::Item* selectedItem = nPlayer.getInventory().getItem(stackInput - 1); //Get the selected item from the player's inventory based on their input (subtracting 1 to convert from 1-based to 0-based index)
			playerStack.push(selectedItem); //The item is added to the player's stack
			tempStack.push_back(selectedItem); //The item is also added to a temporary vector to display the current stack to the player
			nPlayer.getInventory().removeItem(stackInput - 1); //The item is removed from the player's inventory

			// 4. Check Win Condition
			if (playerStack.size() == 5)
			{
				std::cout << "------------------" << std::endl;
				std::cout << "Final stack:" << std::endl;
				for (int i = 0; i < tempStack.size(); i++)
				{
					std::cout << "-" << tempStack.at(i)->getName() << std::endl;
				}
				std::cout << "------------------" << std::endl;
				system("pause");
				if (playerStack == winningStack)
				{
					std::cout << "Congratulations!" << std::endl;
					eventCompleted = true;
					return true;
				}
				else
				{
					std::cout << "Incorrect. Try again!" << std::endl;

					//Return Items to playerInv
					nPlayer.getInventory().addItem(&mug);
					nPlayer.getInventory().addItem(&teabag);
					nPlayer.getInventory().addItem(&sugar);
					nPlayer.getInventory().addItem(&water);
					nPlayer.getInventory().addItem(&milk);

					//Resets the stacks
					playerStack = std::stack<Object::Item*>(); //Reset the player's stack
					tempStack.clear(); //Clear the temporary vector for display
				}
				system("pause");
			}
			maxValidInput = nPlayer.getInventory().getSize();
		}
	}
}
