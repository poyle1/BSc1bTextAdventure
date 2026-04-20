#include <iostream>
#include <string>
#include <windows.h>

#include "EventRoom.h"
#include "Game.h"
#include "Inventory.h"
#include "Item.h"
#include "Key.h"
#include "Location.h"
#include "Player.h"
#include "Quest.h"
#include "RecipeBuilder.h"
#include "Text.h"
#include "Utility.h"
#include "Event.h"
#include "EventJohn.h"

int main()
{
	//Core game initialization//
	GameObject::Game mainGame;
	GameObject::Player mainPlayer;
	//Load world and art assets//
	mainGame.loadWorld("./Data/locationAssets.csv", "./Data/doorAssets.csv", "./Data/itemAssets.csv", "./Data/eventAssets.csv");
	UI::Text::getInstance().loadArtLibrary("./Data/asciiAssets.txt");
	//Set quest and recipe details//
	GameObject::Quest mainQuest("Tea Time", "Bring John a cup of tea.");
	GameObject::RecipeBuilder teaRecipe("a Cup of Tea", 6);

	while (mainGame.getIsRunning())
	{
		//mainGame.mainMenu(); //Main menu, player name input, short intro scene

		GameObject::EventJohn John("sda","asdasd","asdasd",false);
		mainGame.getCurrentLocation()->addEvent(John);

		//Main Game Loop// Quest states are advanced by EventRoom.cpp 
		while (mainQuest.getState() != GameObject::Quest::Completed)
		{
			system("cls");
		
			//Available Actions Logic//
			int numDoors = mainGame.getCurrentLocation()->getNumDoors(); //Doors
			int investigateRoomOption = numDoors + 1; //Doors +1
			int startEventOption = numDoors + 2; //Doors +2

			int numEvents = mainGame.getCurrentLocation()->getEvents().size(); //Events
			int maxValidInput = investigateRoomOption + numEvents; //Doors + 1 + Events
			

			//Current Location & Art//
			mainGame.currentLocationInfo();

			//Inventory Info//
			std::cout << "Collected Items: ";
			mainPlayer.getInventory().outputInventory();

			//Quest Status//
			mainQuest.currentQuestInfo(mainPlayer);

			//Available Actions//
			mainGame.currentActionsInfo(investigateRoomOption, startEventOption);

			//User Input//
			int userInput = UI::getValidIntInput(1, maxValidInput); //1, Doors + 1 + Events
			UI::Text::getInstance().lineBreak();

			if (userInput >= startEventOption)
			{
				int eventIndex = userInput - startEventOption; //eventIndex should always start from 0
				mainGame.getCurrentLocation()->startEvent(teaRecipe, mainPlayer, mainQuest, eventIndex);
				continue;
			}
			/*if (!mainPlayer.getHasActiveQuest())
			{
				std::cout << "You should talk to John first before exploring around." << std::endl;
				UI::pauseAndFlush();
			}*/
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
			}
		}
		//End Game//
		system("cls");
		mainGame.gameOver(mainQuest);
	}
}