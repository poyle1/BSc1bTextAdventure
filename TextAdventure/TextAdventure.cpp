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
#include "BasicEnemy.h"
#include "Text.h"
#include "Game.h"

using namespace std;
using namespace Utility;

stack<Item*> winningStack;
stack<Item*> playerStack;
vector<Item*> playerInventory = {};
int collectedIng = 0;

int main()
{
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	//SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	Text text;
	Game game;
	game.loadLocations("./Data/locationAssets.csv");
	game.loadDoors("./Data/doorAssets.csv");
	
	game.outputWorld();
	cout << game.getCurrentLocation()->getIndex() << endl;
	system("pause");

	Item sugar("Sugar", "", true);
	Item milk("Milk", "", true);
	Item tea("Tea bag", "", true);
	Item mug("Mug", "", true);
	Item water("Water", "", true);

	winningStack.push(&mug);
	winningStack.push(&tea);
	winningStack.push(&sugar);
	winningStack.push(&water);
	winningStack.push(&milk);

	//playerInventory.push_back

	//game.mainMenu();

	
	//Living Room index 0
	//hallway room index 1

	//Doors file columns
	// home room index | destination room index | locked | requiredKeyId

	//while (###) {
		//For each door read
		//Create door object
		//Access desired location object from home room index in vector
		//...
		//...
	//}



	//Look at creation of items, locations, players, etc from files, similar to ascii.

	Key bedroomKey("Bedroom Key", "", true, "1");
	Key kitchenKey("Kitchen Key", "", true, "2");
	Item testItem("Test Item", "debugging.", false);
	/*livingRoom.addItem(&bedroomKey);
	livingRoom.addItem(&sugar);*/




	//livingRoom.setInspectText("This is the living room.");
	//hallWay.setInspectText("This is the hallway.");
	//bedroom.setInspectText("This is the bedroom.");

	//livingRoom.addDoor(&hallWay, false, "");
	//livingRoom.addDoor(&kitchen, true, "2");
	//hallWay.addDoor(&livingRoom, false, "");
	//hallWay.addDoor(&bedroom, true, "1");
	//hallWay.addDoor(&kitchen, false, "");
	//kitchen.addDoor(&livingRoom, false, "");
	//bedroom.addDoor(&hallWay, false, "");

	
	
	//Starting location
//	Location* pCurrentLocation = &livingRoom;
	//Location* pCurrentLocation = game.getLocation("start");
	
	
	

	

	//Main Game Loop//
	while (true)
	{
		//Investigate option will always output as the next option after the last available room
		//Followed by the start event option if present

		int numDoors = game.getCurrentLocation()->getNumDoors();
		//int numDoors = pCurrentLocation->getNumDoors();
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
		for (Item* i : playerInventory) 
		{
			cout << "-" << i->getName() << " ";
		}
		cout << endl;
		cout << "Total Ingredients: " << collectedIng;
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
			game.getCurrentLocation()->investigateRoom(collectedIng, playerInventory);
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