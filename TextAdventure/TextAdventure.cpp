#include <iostream> //cout
#include <fstream> // ifstream and ofstream
#include <string> // getline
#include <vector>
#include <windows.h>
#include <stack>
#include "Utility.h"
#include "Location.h"
#include "EventRoom.h"
#include "Item.h"
#include "Key.h"
#include "Inventory.h"
#include "Player.h"
#include "Text.h"
#include "Game.h"
#include "Quest.h"
#include "RecipeBuilder.h"

int main()
{
	GameObject::Game mainGame;
	GameObject::Player mainPlayer;
	GameObject::Quest mainQuest("Tea Time", "Bring John a cup of tea.");
	GameObject::RecipeBuilder teaRecipe("Cup of Tea");

	mainGame.loadWorld("./Data/locationAssets.csv", "./Data/doorAssets.csv", "./Data/itemAssets.csv");
	UI::Text::getInstance().loadArtLibrary("./Data/asciiAssets.txt");
	//game.mainMenu();

	//Main Game Loop//
	while (true)
	{
		//Available Actions Logic//
		int investigateRoomOption = mainGame.getCurrentLocation()->getNumDoors() + 1;
		int startEventOption = mainGame.getCurrentLocation()->getNumDoors() + 2;
		int maxValidInput = investigateRoomOption;
		if (mainGame.getCurrentLocation()->getIsEventRoom() == true)
		{
			maxValidInput = startEventOption;
		}

		//Current Room Info//
		system("cls");
		UI::Text::getInstance().lineBreak(); ///
		std::cout << "Current location: " << mainGame.getCurrentLocation()->getName() << " | ";
		mainGame.getCurrentLocation()->itemCheck();
		UI::Text::getInstance().lineBreak(); ///
		UI::Text::getInstance().printArt(mainGame.getCurrentLocation()->getName());
		UI::Text::getInstance().lineBreak(); ///
		UI::Text::getInstance().printArt(mainGame.getCurrentLocation()->getName() + "Map");
		UI::Text::getInstance().lineBreak(); ///

		//Inventory and Quest Info//
		std::cout << "Collected Items: ";
		mainPlayer.getInventory().outputInventory();
		std::cout << "Quest: ";
		if (mainPlayer.getHasActiveQuest())
		{
			std::cout << mainQuest.getQuestName() << " - " << mainQuest.getQuestDescription() << std::endl;
			std::cout << "Total Ingredients: " << mainPlayer.getInventory().getQuestItemTotal() << std::endl;
		}
		else
		{
			std::cout << "None" << std::endl;
		}
		UI::Text::getInstance().lineBreak(); ///

		//Available Actions//
		std::cout << "Available Actions:" << "\n";
		mainGame.getCurrentLocation()->outputDoors();
		std::cout << investigateRoomOption << ") Investigate the room" << std::endl;
		if (mainGame.getCurrentLocation()->getIsEventRoom() == true)
		{
			std::cout << startEventOption << ") " << mainGame.getCurrentLocation()->getEventPrompt();
		}
		std::cout << std::endl;
		UI::Text::getInstance().lineBreak(); ///
		std::cout << "Enter a character to complete an action:\n\n";

		//User Input//
		int userInput = UI::getValidIntInput(1, maxValidInput);
		std::cout << std::endl;


		if (userInput == startEventOption)
		{
			mainGame.getCurrentLocation()->startEvent(teaRecipe, mainPlayer, mainQuest);
			//UI::pauseAndFlush();
			continue;
		}
		if (!mainPlayer.getHasActiveQuest())
		{
			std::cout << "You should talk to John first before exploring around." << std::endl;
			UI::pauseAndFlush();
		}
		else
		{
			//Investigate Current Location//
			if (userInput == investigateRoomOption)
			{
				mainGame.getCurrentLocation()->investigateRoom(mainPlayer.getInventory());
				continue;
			}

			int doorIndex = userInput - 1;
			GameObject::Location* chosenLocation = mainGame.getCurrentLocation()->getDoor(doorIndex);

			//Locked Door Check//
			if (mainGame.getCurrentLocation()->isDoorLocked(doorIndex))
			{
				if (!mainGame.getCurrentLocation()->unlockDoor(doorIndex, mainPlayer.getInventory())) {
					std::cout << "The door to the " << chosenLocation->getName() << " is locked!" << std::endl;
					UI::pauseAndFlush();
					continue;
				}
			}
			//Enter Chosen Location//
			mainGame.setCurrentLocation(chosenLocation);
			//mainGame.getCurrentLocation()->enterLocation();
		}
	}
}