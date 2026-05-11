#include "RecipeBuilder.h"

#include <stack>
#include <string>
#include <iostream>
#include <vector>

#include "Utility.h"
#include "Item.h"
#include "Player.h"
#include "Quest.h"
#include "Text.h"

namespace GameObject
{
	RecipeBuilder::RecipeBuilder()
	{
		m_recipeName = "Default Recipe";
		m_recipeSteps = 1;
	}

	RecipeBuilder::RecipeBuilder(std::string nRecipeName, int nRecipeSteps)
	{
		m_recipeName = nRecipeName;
		m_recipeSteps = nRecipeSteps;
	}
	std::string RecipeBuilder::getName() const
	{
		return m_recipeName;
	}
	int RecipeBuilder::getRecipeSteps() const
	{
		return m_recipeSteps;
	}
	bool RecipeBuilder::teaBuilderMkII(Player& nPlayer, Quest& nQuest)
	{
		if (nPlayer.getInventory().getQuestItemTotal() < 6)
		{
			std::cout << "You don't have all the ingredients to make a cup of tea! Come back when you have collected them all." << std::endl;
			UI::pauseAndFlush();
			return false;
		}

		bool eventCompleted = false;

		while (!eventCompleted)
		{
			std::vector<Item*> outputVector;
			int recipeResultScore = 0;
			int currentStep = 0;

			while (currentStep < m_recipeSteps)
			{
				system("cls");
				std::cout << "====================================================================================================\n";
				std::cout << "Make a cup of tea by entering the ingredients in the correct order!" << std::endl;
				std::cout << "Hint: Stir the tea at the end!" << std::endl;
				std::cout << "====================================================================================================\n";

				//Stack Info
				std::cout << "You have: " << std::endl;
				nPlayer.getInventory().outputInventoryWithNumbers();

				if (!outputVector.empty())
				{
					std::cout << "Cup of tea contents:" << std::endl;
					std::cout << "=-=-=-=-=-=-=" << std::endl;
					for (int i = 0; i < outputVector.size(); i++)
					{
						std::cout << "-" << outputVector.at(i)->getName() << std::endl;
					}
					std::cout << "=-=-=-=-=-=-=" << std::endl;
				}

				//Player Input
				std::cout << std::endl;
				std::cout << "Enter the item you want to add to the recipe: ";
				std::cout << std::endl;
				int playerInput = UI::getValidIntInput(1, nPlayer.getInventory().getSize());
				Item* selectedItem = nPlayer.getInventory().getItemViaIndex(playerInput - 1); //Get the selected item from the player's inventory
				std::cout << std::endl;

				if (!selectedItem->isQuestItem())
				{
					std::cout << "That item isn't an ingredient! Please select an ingredient to add to the stack." << std::endl;
					UI::pauseAndFlush();
					continue;
				}

				bool failed = false;
				if (currentStep == 0)
				{
					if (selectedItem->getName() == "Teabag")
					{
						std::cout << "You place a tea bag on the counter. Thats not quite a cup of tea, is it? " << std::endl;
						failed = true;
					}
					else if (selectedItem->getName() == "Sugar")
					{
						std::cout << "You pour sugar onto the counter. I hope you like ants." << std::endl;
						failed = true;
					}
					else if (selectedItem->getName() == "Filled Kettle")
					{
						std::cout << "You pour boiling water onto the kitchen counter. Well done." << std::endl;
						failed = true;
					}
					else if (selectedItem->getName() == "Milk")
					{
						std::cout << "You pour milk onto the kitchen counter. It's a dairy disaster." << std::endl;
						failed = true;
					}
					else if (selectedItem->getName() == "Spoon")
					{
						std::cout << "You stir thin air with the spoon. It is fun to pretend, but you have work to do." << std::endl;
						failed = true;
					}
					else if (selectedItem->getName() == "Mug")
					{
						std::cout << "You place the mug on the counter." << std::endl;
						selectedItem->setScoreValue(score2DArray[0][currentStep]);
					}
				}
				else
				{
					if (selectedItem->getName() == "Sugar" || selectedItem->getName() == "Teabag")
					{
						std::cout << "You put the " << selectedItem->getName() << " in the mug." << std::endl;
						selectedItem->setScoreValue(score2DArray[1][currentStep]);
					}
					else if (selectedItem->getName() == "Filled Kettle")
					{
						std::cout << "You pour water into the mug." << std::endl;
						selectedItem->setScoreValue(score2DArray[3][currentStep]);
					}
					else if (selectedItem->getName() == "Milk")
					{
						std::cout << "You pour milk into the mug." << std::endl;
						selectedItem->setScoreValue(score2DArray[4][currentStep]);
					}
					else if (selectedItem->getName() == "Spoon")
					{
						std::cout << "You stir the contents of the mug." << std::endl;
						selectedItem->setScoreValue(score2DArray[5][currentStep]);
					}
				}

				if (failed) //Returns items to the player and returns the steps
				{
					std::cout << "...lets try again!" << std::endl;
					for (int i = 0; i < outputVector.size(); i++)
					{
						nPlayer.getInventory().addItem(outputVector.at(i));
					}
					outputVector.clear();
					recipeResultScore = 0;
					currentStep = 0;
					UI::pauseAndFlush();
				}
				else //Success - Items are moved to the stack
				{
					outputVector.push_back(selectedItem);
					recipeResultScore += selectedItem->getScoreValue();
					nPlayer.getInventory().removeItem(playerInput - 1);
					currentStep++;
					UI::pauseAndFlush();
				}

				//Check Win Condition
				if (currentStep == m_recipeSteps)
				{
					system("cls");
					std::cout << "====================================================================================================\n";
					std::cout << "--Tea Completed!--" << std::endl;
					std::cout << "====================================================================================================\n";
					std::cout << "You remove the teabag, finishing the cup of tea.\n\n";
					std::cout << "=-=-=-=-=-=-=" << std::endl;
					std::cout << "TEA SCORE: " << recipeResultScore << std::endl;
					std::cout << "=-=-=-=-=-=-=\n\n";
					std::cout << "Would you like to try again?" << std::endl;
					std::cout << "1) Yes" << std::endl;
					std::cout << "2) No" << std::endl;
					int playerChoice = UI::getValidIntInput(1, 2);
					if (playerChoice == 1) //Try again - returns items to the player and resets the steps
					{
						UI::Text::getInstance().lineBreak();
						std::cout << "You pour the tea down the sink and start again!" << std::endl;
						for (int i = 0; i < outputVector.size(); i++)
						{
							nPlayer.getInventory().addItem(outputVector.at(i));
						}
						outputVector.clear();
						recipeResultScore = 0;
						currentStep = 0;
						UI::pauseAndFlush();
					}
					else //Player 
					{
						std::cout << "You are happy with the tea you made. Now deliver it to John." << std::endl;
						Item* tea = new Item("Cup of Tea", "A tea for John.", true);
						tea->setScoreValue(recipeResultScore);
						nPlayer.getInventory().addItem(tea);
						UI::pauseAndFlush();
						return true;
					}
				}
			}
		}
	}
}