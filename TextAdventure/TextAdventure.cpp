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

namespace UI = MilkAndSugar::UI;
namespace World = MilkAndSugar::World;


std::stack<Item*> winningStack;
std::stack<Item*> playerStack;

int main()
{
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	//SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	Text text;
	Game game;
	World::Inventory playerInventory;
	game.loadWorld("./Data/locationAssets.csv", "./Data/doorAssets.csv", "./Data/itemAssets.csv");
	
	//game.outputWorld();
	//game.getCurrentLocation()->outputItems();
	//cout << game.getCurrentLocation()->getIndex() << std::endl;

	std::vector<std::string> test = { "Hello", "World", "Test" };

	for (std::string i : test)
	{
		std::cout << i << " ";
	}

	system("pause");

	/*Item sugar("Sugar", "", true);
	Item milk("Milk", "", true);
	Item tea("Tea bag", "", true);
	Item mug("Mug", "", true);
	Item water("Water", "", true);

	winningStack.push(&mug);
	winningStack.push(&tea);
	winningStack.push(&sugar);
	winningStack.push(&water);
	winningStack.push(&milk);*/

	//playerInventory.push_back
	//game.mainMenu();

	//Main Game Loop//
	while (true)
	{
		//Investigate option will always output as the next option after the last available room
		//Followed by the start event option if present

		int numDoors = game.getCurrentLocation()->getNumDoors();
		int investigateRoomOption = numDoors + 1;
		int startEventOption = numDoors + 2;

		int maxValidInput = investigateRoomOption;
		if (game.getCurrentLocation()->canStartEvent())
		{
			maxValidInput = startEventOption; // if event room, option to use
		}

		//Current Room Info//
		system("cls");
		std::cout << "====================================================================================================\n";
		std::cout << "Current location: " << game.getCurrentLocation()->getName() << "\n";
		game.getCurrentLocation()->itemCheck();
		std::cout << "====================================================================================================\n";
		std::cout << "Collected Items: ";
		playerInventory.outputInventory();
		std::cout << std::endl;
		std::cout << "Total Ingredients: " << playerInventory.getQuestItemTotal();
		std::cout << std::endl;
		std::cout << "====================================================================================================\n";
		text.printArt(game.getCurrentLocation()->getName());
		std::cout << "====================================================================================================\n";
		std::cout << "Available Actions:" << "\n";
		game.getCurrentLocation()->outputDoors();
		std::cout << investigateRoomOption << ") Investigate the room" << std::endl;
		if (game.getCurrentLocation()->canStartEvent())
		{
			std::cout << startEventOption << ") " << game.getCurrentLocation()->getEventPrompt();
		}
		std::cout << std::endl;
		std::cout << "====================================================================================================\n";
		std::cout << "Enter a character to complete an action:\n\n";

		//User Input//
		int userInput = UI::getValidIntInput(1, maxValidInput);
		std::cout << std::endl;

		//Investigate Current Location//
		if (userInput == investigateRoomOption)
		{
			game.getCurrentLocation()->investigateRoom(playerInventory);
			UI::pauseAndFlush();
			continue;
		}

		if (game.getCurrentLocation()->canStartEvent() && userInput == startEventOption)
		{
			game.getCurrentLocation()->startEvent();
			UI::pauseAndFlush();
			continue;
		}

		int doorIndex = userInput - 1;
		Location* chosenLocation = game.getCurrentLocation()->getDoor(doorIndex);

		
		//Locked Door Check//
		if (game.getCurrentLocation()->isDoorLocked(doorIndex))
		{
			if (!game.getCurrentLocation()->unlockDoor(doorIndex, playerInventory)) {
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