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

using namespace std;
using namespace Utility;

stack<Item*> winningStack;
stack<Item*> playerStack;

int main()
{
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	//SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	Text text;
	Game game;
	Inventory playerInventory;
	game.loadWorld("./Data/locationAssets.csv", "./Data/doorAssets.csv", "./Data/itemAssets.csv");
	
	//game.outputWorld();
	//game.getCurrentLocation()->outputItems();
	//cout << game.getCurrentLocation()->getIndex() << endl;
	//system("pause");

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
		cout << "====================================================================================================\n";
		cout << "Current location: " << game.getCurrentLocation()->getName() << "\n";
		game.getCurrentLocation()->itemCheck();
		cout << "====================================================================================================\n";
		cout << "Collected Items: ";
		playerInventory.outputInventory();
		cout << endl;
		cout << "Total Ingredients: " << playerInventory.getQuestItemTotal();
		cout << endl;
		cout << "====================================================================================================\n";
		text.printArt(game.getCurrentLocation()->getName());
		cout << "====================================================================================================\n";
		cout << "Available Actions:" << "\n";
		game.getCurrentLocation()->outputDoors();
		cout << investigateRoomOption << ") Investigate the room" << endl;
		if (game.getCurrentLocation()->canStartEvent())
		{
			cout << startEventOption << ") " << game.getCurrentLocation()->getEventPrompt();
		}
		cout << endl;
		cout << "====================================================================================================\n";
		cout << "Enter a character to complete an action:\n\n";

		//User Input//
		int userInput = getValidIntInput(1, maxValidInput);
		cout << endl;

		//Investigate Current Location//
		if (userInput == investigateRoomOption)
		{
			game.getCurrentLocation()->investigateRoom(playerInventory);
			pauseAndFlush();
			continue;
		}

		if (game.getCurrentLocation()->canStartEvent() && userInput == startEventOption)
		{
			game.getCurrentLocation()->startEvent();
			pauseAndFlush();
			continue;
		}

		int doorIndex = userInput - 1;
		Location* chosenLocation = game.getCurrentLocation()->getDoor(doorIndex);

		
		//Locked Door Check//
		if (game.getCurrentLocation()->isLocked(doorIndex))
		{
			if (!game.getCurrentLocation()->unlockDoor(doorIndex, playerInventory)) {
				cout << "The door is locked - you cannot open it!" << endl;
				pauseAndFlush();
				continue; 
			}
		}
		//Enter Chosen Location//
		game.setCurrentLocation(chosenLocation);
		game.getCurrentLocation()->enterLocation();
	}
}