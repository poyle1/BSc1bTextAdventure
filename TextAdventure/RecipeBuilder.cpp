#include "RecipeBuilder.h"

#include <stack>
#include <iostream>
#include "Utility"
#include "Utility.h"
#include "Item.h"
#include "Player.h"
#include "Quest.h"

namespace GameObject
{
	RecipeBuilder::RecipeBuilder()
	{
		m_recipeName = "Default Recipe";
	}

	RecipeBuilder::RecipeBuilder(std::string nRecipeName)
	{
		m_recipeName = nRecipeName;
	}

	bool RecipeBuilder::teaBuilder(Player& nPlayer, Quest& nQuest)
	{
		if (nPlayer.getInventory().getQuestItemTotal() < 5)
		{
			std::cout << "You don't have all the ingredients to make a cup of tea! Come back when you have collected them all." << std::endl;
			UI::pauseAndFlush();
			return false;
		}
		std::stack<Item*> winningStack1; //best outcome
		std::stack<Item*> winningStack2; //best outcome
		std::stack<Item*> winningStack3; //okay outcome
		std::stack<Item*> winningStack4; //okay outcome

		std::stack<Item*> playerStack;
		std::vector<Item*> outputVector;

		Item mug("Mug1", "1", true);
		Item teabag("Tea bag2", "2", true);
		Item sugar("Sugar3", "3", true);
		Item water("Water4", "4", true);
		Item milk("Milk5", "5", true);

		winningStack1.push(&mug);
		winningStack1.push(&teabag);
		winningStack1.push(&sugar);//Sugar can be added before or after the teabag
		winningStack1.push(&water);
		winningStack1.push(&milk);

		winningStack2.push(&mug);
		winningStack2.push(&sugar);//Sugar can be added before or after the teabag
		winningStack2.push(&teabag);
		winningStack2.push(&water);
		winningStack2.push(&milk);

		winningStack3.push(&mug);
		winningStack3.push(&water);
		winningStack3.push(&teabag);
		winningStack3.push(&sugar);//Sugar can be added before or after the teabag
		winningStack3.push(&milk);

		winningStack4.push(&mug);
		winningStack4.push(&water);
		winningStack4.push(&sugar);//Sugar can be added before or after the teabag
		winningStack4.push(&teabag);
		winningStack4.push(&milk);

		bool eventCompleted = false;
		int maxValidInput = nPlayer.getInventory().getSize();

		while (!eventCompleted)
		{
			system("cls");
			std::cout << "====================================================================================================\n";
			std::cout << "Make a cup of tea by entering the ingredients in the correct order!" << std::endl;
			std::cout << "Hint: Milk is added last!" << std::endl;
			std::cout << "====================================================================================================\n";

			//Stack Info
			std::cout << "You have: " << std::endl;
			nPlayer.getInventory().outputInventoryWithNumbers();
			
			if (!outputVector.empty())
			{
				std::cout << "Current Stack:" << std::endl;
				std::cout << "=-=-=-=-=-=-=" << std::endl;
				for (int i = 0; i < outputVector.size(); i++)
				{
					std::cout << "-" << outputVector.at(i)->getName() << std::endl;
				}
				std::cout << "=-=-=-=-=-=-=" << std::endl;
			}
			
			//Player Input
			std::cout << std::endl;
			std::cout << "Enter the item you want to add to the stack: ";
			std::cout << std::endl;
			int stackInput = UI::getValidIntInput(1, nPlayer.getInventory().getSize());
			std::cout << std::endl;

			//Update Game State
			Item* selectedItem = nPlayer.getInventory().getItem(stackInput - 1); //Get the selected item from the player's inventory
			if (!selectedItem->isQuestItem())
			{
				std::cout << "That item isn't an ingredient! Please select an ingredient to add to the stack." << std::endl;
				UI::pauseAndFlush();
				continue; //Skip the rest of the loop and prompt the player for input again
			}
			playerStack.push(selectedItem); //The item is added to the player's stack
			outputVector.push_back(selectedItem); //The item is also added to a vector to display the current stack
			nPlayer.getInventory().removeItem(stackInput - 1); //The item is removed from the player's inventory

			//Check Win Condition
			if (playerStack.size() == 5)
			{
				
				std::cout << "Final stack:" << std::endl;
				std::cout << "------------------" << std::endl;
				for (int i = 0; i < outputVector.size(); i++)
				{
					std::cout << "-" << outputVector.at(i)->getName() << std::endl;
				}
				std::cout << "------------------" << std::endl;
				
				if (playerStack == winningStack3 || playerStack == winningStack4)
				{
					std::cout << "You have made a cup of tea - although in a very strange order..." << std::endl;
					std::cout << "Now bring it to John." << std::endl;
					nQuest.advanceState(Quest::Achieved, nPlayer);
					eventCompleted = true;
					return true;
				}
				if (playerStack == winningStack1 || playerStack == winningStack2)
				{
					std::cout << "You have successfully made a good cup of tea!" << std::endl;
					std::cout << "Now bring it to John." << std::endl;
					nQuest.advanceState(Quest::Achieved, nPlayer);
					eventCompleted = true;
					return true;
				}
				else
				{
					std::cout << "You've mad a tea... but it isn't very good. Try again!" << std::endl;
					for (int i = 0; i < outputVector.size(); i++)
					{
						nPlayer.getInventory().addItem(outputVector.at(i)); //Return the items to the player's inventory
					}

					//Resets the stacks
					playerStack = std::stack<Item*>(); //Reset the player's stack
					outputVector.clear(); //Reset the output vector
					system("pause");
				}
				system("pause");
			}
			maxValidInput = nPlayer.getInventory().getSize();
		}
	}
}
