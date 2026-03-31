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

std::stack<Object::Item*> winningStack;
std::stack<Object::Item*> playerStack;
std::stack<Object::Item*> tempStack;

int main()
{
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	//SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	UI::Text text;
	Core::Game game;
	World::Inventory playerInventory;

	game.loadWorld("./Data/locationAssets.csv", "./Data/doorAssets.csv", "./Data/itemAssets.csv");
	
	//game.outputWorld();
	//game.getCurrentLocation()->outputItems();
	//cout << game.getCurrentLocation()->getIndex() << std::endl;

	/*std::vector<std::string> test = { "Hello", "World", "Test" };

	for (std::string i : test)
	{
		std::cout << i << " ";
	}*/


	Object::Item mug1("Mug1", "1", true);
	Object::Item teabag2("Tea bag2", "2", true);
	Object::Item sugar3("Sugar3", "3", true);
	Object::Item water4("Water4", "4", true);
	Object::Item milk5("Milk5", "5", true);

	winningStack.push(&mug1);
	winningStack.push(&teabag2);
	winningStack.push(&sugar3);
	winningStack.push(&water4);
	winningStack.push(&milk5);

	playerInventory.addItem(&mug1);
	playerInventory.addItem(&teabag2);
	playerInventory.addItem(&sugar3);
	playerInventory.addItem(&water4);
	playerInventory.addItem(&milk5);

	
	
	
	bool eventCompleted = false;
	bool stackComplete = false;

	while (!eventCompleted)
	{
		int maxValidInput = playerInventory.getSize() + 1;
		playerInventory.outputInventory();
		std::cout << "Enter the name of the item you want to add to the stack: ";
		int stackInput = UI::getValidIntInput(1, maxValidInput);
		playerStack.push(playerInventory.getItem(stackInput - 1));
		
		// Shifting INPUT to the end of vector
		std::erase(find(playerInventory.getItems().begin(), playerInventory.getItems().end(), stackInput - 1));
		// Deleting the last element i.e. INPUT
		//playerInventory.getItems().pop_back();



	}
	while (!eventCompleted)
	{
		if (stackComplete == true && playerStack == winningStack)
		{

			std::cout << "Congratulations! You have made the perfect cup of tea and completed the event!" << std::endl;
			eventCompleted = true;
			system("pause");
		}
		std::cout << "Enter the name of the item you want to add to the stack: ";
		//std::cin >> playerInput1;

		int selectedIndex = -1;

	}

	system("pause");

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
		World::Location* chosenLocation = game.getCurrentLocation()->getDoor(doorIndex);

		
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