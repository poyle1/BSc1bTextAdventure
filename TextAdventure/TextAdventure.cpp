#include <iostream>
#include <string>
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

using namespace std;
using namespace Utility;

void gameIntro();
void acsii1();
void titleScreen();
void asciiArt(Location& pCurrentLocation);
void enterLocation(Location* nloc);

stack<Item*> winningStack;

int main()
{
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

	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	gameIntro();
	titleScreen();
	
	Location livingRoom("Living Room");
	Location hallWay("Hallway");
	Location bedroom("Bedroom");
	EventRoom kitchen("Kitchen", "Make a cup of tea");
	Location bathroom1("Bathroom");
	Location bathroom2("En Suite Bathroom");
	Location frontGarden("Front Garden");
	Location backGarden("Back Garden");
	Location shed("Shed");

	//Look at creation of items, locations, players, etc from files, similar to ascii.

	Key bedroomKey("Bedroom Key", "", true, "1");
	Key kitchenKey("Kitchen Key", "", true, "2");
	Item testItem("Test Item", "debugging.", false);
	livingRoom.addItem(&bedroomKey);
	livingRoom.addItem(&sugar);

	livingRoom.setInspectText("This is the living room.");
	hallWay.setInspectText("This is the hallway.");
	bedroom.setInspectText("This is the bedroom.");

	livingRoom.addDoor(&hallWay, false, "");
	livingRoom.addDoor(&kitchen, true, "2");
	hallWay.addDoor(&livingRoom, false, "");
	hallWay.addDoor(&bedroom, true, "1");
	hallWay.addDoor(&kitchen, false, "");
	kitchen.addDoor(&livingRoom, false, "");
	bedroom.addDoor(&hallWay, false, "");
	
	//Starting location
	Location* pCurrentLocation = &livingRoom;
	vector<Item*> playerInventory = {};
	int collectedIng = 0;

	//Main Game Loop//
	while (true)
	{
		//Investigate option will always output as the next option after the last available room
		//Followed by the start event option if present
		int numDoors = pCurrentLocation->getNumDoors();
		int investigateRoomOption = numDoors + 1;
		int startEventOption = numDoors + 2;

		int maxValidInput = investigateRoomOption;
		if (pCurrentLocation->canStartEvent())
		{
			maxValidInput = startEventOption; // if event room, option to use
		}

		//Current Room Info//
		system("cls");
		cout << "====================================================================================================\n";
		cout << "Current location: " << pCurrentLocation->getName() << "\n";
		pCurrentLocation->itemCheck();
		cout << "====================================================================================================\n";
		cout << "Collected Items: ";
		for (Item* i : playerInventory) {
			cout << "-" << i->getName() << " ";
		}
		cout << endl;
		cout << "Total Ingredients: " << collectedIng;
		cout << endl;
		cout << "====================================================================================================\n";
		asciiArt(*pCurrentLocation);
		cout << "====================================================================================================\n";
		cout << "Available Actions:" << "\n";
		pCurrentLocation->outputDoors();
		cout << investigateRoomOption << ") Investigate the room" << endl;
		if (pCurrentLocation->canStartEvent())
		{
			cout << startEventOption << ") " << pCurrentLocation->getEventPrompt();
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
			pCurrentLocation->investigateRoom(collectedIng, playerInventory);
			pauseAndFlush();
			continue;
		}

		if (pCurrentLocation->canStartEvent() && userInput == startEventOption)
		{
			pCurrentLocation->startEvent();
			pauseAndFlush();
			continue;
		}

		int doorIndex = userInput - 1;
		Location* chosenLocation = pCurrentLocation->getDoor(doorIndex);
		
		//Locked Door Check//
		if (pCurrentLocation->isLocked(doorIndex))
		{
			if (!pCurrentLocation->unlockDoor(doorIndex, playerInventory)) {
				cout << "The door is locked - you cannot open it!" << endl;
				pauseAndFlush();
				continue; 
			}
		}
		//Enter Chosen Location//
		pCurrentLocation = chosenLocation;
		enterLocation(pCurrentLocation);
	}
}
