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
#include "Common.h"
#include "Quest.h"
#include "RecipeBuilder.h"

int main()
{
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	//SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	UI::Text mainText;
	Core::Game mainGame;
	Object::Player mainPlayer;
	Core::Quest mainQuest("Tea Time", "Bring John a cup of tea.");
	Core::RecipeBuilder teaRecipe("Cup of Tea");

	mainGame.loadWorld("./Data/locationAssets.csv", "./Data/doorAssets.csv", "./Data/itemAssets.csv");
	mainText.loadArtLibrary("./Data/asciiAssets.txt");
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
		mainText.lineBreak(); ///
		std::cout << "Current location: " << mainGame.getCurrentLocation()->getName() << "\n";
		mainText.lineBreak(); ///
		mainText.printArt(mainGame.getCurrentLocation()->getName());
		mainText.lineBreak(); ///
		mainText.printArt(mainGame.getCurrentLocation()->getName() + "Map");
		mainText.lineBreak(); ///
		mainGame.getCurrentLocation()->itemCheck();
		mainText.lineBreak(); ///

		//Inventory and Quest Info//
		std::cout << "Collected Items: ";
		mainPlayer.getInventory().outputInventory();
		mainText.lineSpace(); ///
		std::cout << "Total Ingredients: " << mainPlayer.getInventory().getQuestItemTotal();
		mainText.lineSpace(); ///
		mainText.lineBreak(); ///

		//Available Actions//
		std::cout << "Available Actions:" << "\n";
		mainGame.getCurrentLocation()->outputDoors();
		std::cout << investigateRoomOption << ") Investigate the room" << std::endl;
		std::cout << startEventOption << ") " << mainGame.getCurrentLocation()->getEventPrompt();
	
		std::cout << std::endl;
		mainText.lineBreak(); ///
		std::cout << "Enter a character to complete an action:\n\n";

		//User Input//
		int userInput = UI::getValidIntInput(1, maxValidInput);
		std::cout << std::endl;


		if (userInput == startEventOption)
		{
			mainGame.getCurrentLocation()->startEvent(teaRecipe, mainPlayer, mainQuest);
			UI::pauseAndFlush();
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
				UI::pauseAndFlush();
				continue;
			}

			int doorIndex = userInput - 1;
			World::Location* chosenLocation = mainGame.getCurrentLocation()->getDoor(doorIndex);

			//Locked Door Check//
			if (mainGame.getCurrentLocation()->isDoorLocked(doorIndex))
			{
				if (!mainGame.getCurrentLocation()->unlockDoor(doorIndex, mainPlayer.getInventory())) {
					std::cout << "The door is locked - you cannot open it!" << std::endl;
					UI::pauseAndFlush();
					continue;
				}
			}
			//Enter Chosen Location//
			mainGame.setCurrentLocation(chosenLocation);
			mainGame.getCurrentLocation()->enterLocation();
		}
	
	}
}