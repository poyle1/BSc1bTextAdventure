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

	UI::Text text;
	Core::Game game;
	Object::Player player;
	Core::Quest mainQuest("Tea Time", "Bring John a cup of tea.");
	Core::RecipeBuilder teaRecipe("Cup of Tea");

	game.loadWorld("./Data/locationAssets.csv", "./Data/doorAssets.csv", "./Data/itemAssets.csv");
	
	//game.mainMenu();

	//Main Game Loop//
	while (true)
	{
		//Available Actions Logic//
		int investigateRoomOption = game.getCurrentLocation()->getNumDoors() + 1;
		int startEventOption = game.getCurrentLocation()->getNumDoors() + 2;
		int maxValidInput = investigateRoomOption;
		if (game.getCurrentLocation()->canStartEvent(player.getInventory(),1))
		{
			maxValidInput = startEventOption;
		}

		//Current Room Info//
		system("cls");
		text.lineBreak(); ///
		std::cout << "Current location: " << game.getCurrentLocation()->getName() << "\n";
		text.lineBreak(); ///
		text.printArt(game.getCurrentLocation()->getName()+"Map");
		text.lineBreak(); ///
		game.getCurrentLocation()->itemCheck();
		text.lineBreak(); ///

		//Inventory and Quest Info//
		std::cout << "Collected Items: ";
		player.getInventory().outputInventory();
		text.lineSpace(); ///
		std::cout << "Total Ingredients: " << player.getInventory().getQuestItemTotal();
		text.lineSpace(); ///
		text.lineBreak(); ///
		text.printArt(game.getCurrentLocation()->getName());
		text.lineBreak(); ///

		//Available Actions//
		std::cout << "Available Actions:" << "\n";
		game.getCurrentLocation()->outputDoors();
		std::cout << investigateRoomOption << ") Investigate the room" << std::endl;
		if (game.getCurrentLocation()->canStartEvent(player.getInventory(),1))
		{
			std::cout << startEventOption << ") " << game.getCurrentLocation()->getEventPrompt();
		}
		std::cout << std::endl;
		text.lineBreak(); ///
		std::cout << "Enter a character to complete an action:\n\n";

		//User Input//
		int userInput = UI::getValidIntInput(1, maxValidInput);
		std::cout << std::endl;

		//Investigate Current Location//
		if (userInput == investigateRoomOption)
		{
			game.getCurrentLocation()->investigateRoom(player.getInventory());
			UI::pauseAndFlush();
			continue;
		}

		if (game.getCurrentLocation()->canStartEvent(player.getInventory(),1) && userInput == startEventOption)
		{
			game.getCurrentLocation()->startEvent(teaRecipe, player, mainQuest);
			UI::pauseAndFlush();
			continue;
		}

		int doorIndex = userInput - 1;
		World::Location* chosenLocation = game.getCurrentLocation()->getDoor(doorIndex);
		
		//Locked Door Check//
		if (game.getCurrentLocation()->isDoorLocked(doorIndex))
		{
			if (!game.getCurrentLocation()->unlockDoor(doorIndex, player.getInventory())) {
				std::cout << "The door is locked - you cannot open it!" << std::endl;
				UI::pauseAndFlush();
				continue; 
			}
		}
		//Enter Chosen Location//
		game.setCurrentLocation(chosenLocation);
		game.getCurrentLocation()->enterLocation();
	}
}