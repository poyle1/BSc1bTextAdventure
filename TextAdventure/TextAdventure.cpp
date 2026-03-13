#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "Location.h"
#include "EventRoom.h"
#include "Item.h"
#include "Key.h"
#include "Inventory.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "FreeFunctions.h"
#include <stack>

using namespace std;

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

	//gameIntro();
	//titleScreen();
	
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
void gameIntro()
{
	acsii1();
	cout << "\"Hello!\"" << endl;
	cout << "\"Thank you for popping round.\"" << endl << endl;
	pauseAndWipe();
	acsii1();
	cout << "\"I get very lonely sometimes...\"" << endl << endl;
	pauseAndWipe();
	acsii1();
	cout << "\"Would you like me to tell you a story?\"" << endl << endl;
	pauseAndWipe();
	acsii1();
	cout << "\"Its about history!\"" << endl << endl;
	pauseAndWipe();
	acsii1();
	cout << "\"Lost history...\"" << endl << endl;
	pauseAndWipe();
	acsii1();
	cout << "\"But first, can you make me a cup of tea?\"" << endl << endl;
	system("pause");
}

void acsii1() {
	cout << "                                                           \n"
		"   .:::.                   .:::..                          \n"
		"   -++++-                  -+++=.                          \n"
		"   -+++++----------=========+++=.                          \n"
		"   -+++++=...........      -+++=.                          \n"
		"   -++++==.                -++++...:+@@@@@%+..             \n"
		"   -++++==-::::::::::::::::-+++*%@@@*-:...:+@@*.           \n"
		"   -+++++=::::::::::::::::-*%@@*-:.         .-@@=          \n"
		"   -+++++=.            .+@@#.        -@-  -@-  .%@-        \n"
		"   -+++++:            :@@%.              .     .@@         \n"
		"   -+++++:   .:=*@@@###**-       :.     (====)  *@         \n"
		"   -+++++: .-@@@-             #@@@@%-.          *@         \n"
		"   -+++++. =@@+.             .%@%..+@@%-.      -@%         \n"
		"   -++++-.*@@*.              .@@%    :+%@@@@@@@@#:         \n"
		"   -++++-+@@+                .@@@-                         \n"
		"   -++++@@@=.                 .*@#.                        \n"
		"   -++++@@@.                 .  .%@+.                      \n"
		"   -++++%@@*.                 .    -#@%=..                 \n"
		"   -+++-=*%@@#:     +##%%%%%%%#***=.  .-@@#.               \n"
		"   -+++: .:=#%@@#+-.  :*@@@*.    .=@@%- .+@@+.             \n"
		"   -+++:     .++*%@@@#:. :@@@:     .%@@:. -@@-             \n"
		"   -+++:     .+++++-#@@:  %@@:      :#@@= .@@:             \n"
		"   -+++:     .+++++-+@@: =@@*        =@@= :@@:             \n"
		"   -+++:     .+++++-+@@: +@@-        =@@= :@%.             \n"
		"   -+++:     .+++++-+@@: +@@-        =@@= -@%.             \n"
		"   -+++:     .+++++-+@@: +@@-        =@@= =@%.             \n"
		"   -+++:     .+++++-%@@: +@@-        =@@= =@#.             \n"
		"   .....     .+++++-%@%. :@@#        =@@= -@#.             \n"
		"             .+++++-%@%: .@@@.       .@@#.:@@-             \n"
		"             .+++++-+@@:  *@@@@@@@#+..%@%.:%@@@@@%*-..     \n"
		"             .+++++--@@%.       .=@@%.=@@*--::::+%@@@.     \n"
		"             .-----: .-++++++++++++:. .-=========-.        \n"
		"                                                           " << endl;
}

void titleScreen()
{
	system("cls");
	cout << "+----------------------------------------------------------------------------------+\n"
"|    __  __ _ _ _       ___      ___               ____                            |\n"
"|   |  \\/  (_) | | __  ( _ )    / _ \\ _ __   ___  / ___| _   _  __ _  __ _ _ __    |\n"
"|   | |\\/| | | | |/ /  / _ \\/\\ | | | | '_ \\ / _ \\ \\___ \\| | | |/ _` |/ _` | '__|   |\n"
"|   | |  | | | |   <  | (_>  < | |_| | | | |  __/  ___) | |_| | (_| | (_| | |      |\n"
"|   |_|  |_|_|_|_|\\_\\  \\___/\\/  \\___/|_| |_|\\___| |____/ \\__,_|\\__, |\\__,_|_|      |\n"
"|                                                              |___/               |\n"
"+----------------------------------------------------------------------------------+" << endl << endl;
	system("pause");
	cout << endl;
}

void asciiArt(Location& currentLocation) {
	if (currentLocation.getName() == "Living Room") {
		cout << "                                                             \n"
"                                                             \n"
"           .................................:::...           \n"
"         ...+***********************@******##*****=.         \n"
"         .========+****#**###*******%***#**+=======.         \n"
"      .-+##=====+++****#*+****##****%*****++++=+==##+-.      \n"
"     .=***#*==+++++******++++*******%+++**+++++==*#***+.     \n"
"     .=++*##=+++++++#**********************##*+++##***=.     \n"
"     .=+++*#*#***********************%************#+++=.     \n"
"     .=+++*+************+************#++**********#+++=.     \n"
"     ..#%%%%%%%%%%%%%%%%%######%%%%%%%%%%%%%%%%#####*+.      \n"
"      .***************************+*++++++++++++++++++.      \n"
"      .+%*....:::::::::::::::::::::::::::::::......*%+.      \n"
"       .:.                                        ..:.       \n"
"                                                             \n"
"                                                             " << endl;
	}
	else if (currentLocation.getName() == "Church Courtyard") {
		cout << "" << endl;
	}
	else if (currentLocation.getName() == "Ruined Church") {
		cout << "" << endl;
	}
}

// Displays the entry text of the location when the player enters it
void enterLocation(Location* loc)
{
	cout << "You have entered the " << loc->getName() << "." << endl;
	pauseAndFlush();
}