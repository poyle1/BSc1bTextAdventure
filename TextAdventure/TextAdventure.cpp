#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "Location.h"
#include "Item.h"
#include "Key.h"
#include "Inventory.h"
#include "Player.h"
#include "BasicEnemy.h"
#include "FreeFunctions.h"

using namespace std;

void gameIntro();
void acsii1();
void titleScreen();
void pauseAndFlush();
void pauseAndWipe();
void asciiArt(Location& pCurrentLocation);
void enterLocation(Location* nloc);

int main()
{
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	//gameIntro();
	//titleScreen();
	
	Location livingRoom("Living Room");
	Location hallWay("Hallway");
	Location bedroom("Bedroom");
	Location kitchen("Kitchen");
	Location bathroom1("Bathroom");
	Location bathroom2("En Suite Bathroom");
	Location frontGarden("Front Garden");
	Location backGarden("Back Garden");
	Location shed("Shed");

	//Look at creation of items, locations, players, etc from files, similar to ascii.


	Key bedroomKey("Bedroom Key", "", true, "1");
	Key kitchenKey("Kitchen Key", "", true, "2");
	Item sugar("Sugar", "A lovely bag of sugar.");
	Item testItem("Test Item", "debugging.");
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
	

	//livingRoom.addConnection(&hallWay, false, "");
	//livingRoom.addConnection(&kitchen, true, "2");
	//hallWay.addConnection(&livingRoom);
	//hallWay.addConnection(&bedroom);
	//hallWay.addConnection(&kitchen);
	//hallWay.addConnection(&frontGarden);
	//hallWay.addConnection(&backGarden);
	//hallWay.addConnection(&bathroom1);
	//frontGarden.addConnection(&hallWay);
	//frontGarden.addConnection(&backGarden);
	//frontGarden.addConnection(&garage);
	//backGarden.addConnection(&hallWay);
	//backGarden.addConnection(&frontGarden);
	//backGarden.addConnection(&shed);
	//backGarden.addConnection(&garage);
	//shed.addConnection(&backGarden);
	//bedroom.addConnection(&hallWay);
	//bedroom.addConnection(&bathroom2);
	//bathroom1.addConnection(&hallWay);
	//bathroom2.addConnection(&bedroom);
	//kitchen.addConnection(&livingRoom);
	//kitchen.addConnection(&hallWay);
	//kitchen.addConnection(&garage);
	//garage.addConnection(&kitchen);
	//garage.addConnection(&backGarden);
	//garage.addConnection(&frontGarden);
	
	//Starting location
	Location* pCurrentLocation = &livingRoom;

	vector<Item*> playerInventory = {};

	playerInventory.push_back(&testItem);

	while (true)
	{
		system("cls");
		cout << "====================================================================================================\n";
		cout << "Current location: " << pCurrentLocation->getName() << "\n";
		if (pCurrentLocation->hasItems()) {
			cout << "There may be items in this room." << endl;
		}
		else {
			cout << "There are no items in this room." << endl;
		}
		cout << "====================================================================================================\n";
		cout << "Collected Items: ";
		for (Item* i : playerInventory) {
			cout << "-" << i->getName() << " ";
		}
		cout << endl;
		cout << "====================================================================================================\n";
		asciiArt(*pCurrentLocation);
		cout << "====================================================================================================\n";
		cout << "Enter a number to go to a location:\n";
		cout << "Or enter '0' to learn more about your current location.\n\n";
		
		cout << "Available Locations:" << "\n";
		pCurrentLocation->outputConnections();
		cout << "====================================================================================================\n\n";

		int userInput = getValidIntInput(0, pCurrentLocation->getNumConnections());
		cout << endl;

		//Investigate current location
		if (userInput == 0)
		{
			cout << pCurrentLocation->getInspectText() << endl;
			if (pCurrentLocation->hasItems()) 
			{
				cout << endl;
				cout << "You search the room and collect:" << endl;
				for (Item* i : pCurrentLocation->getItems()) 
				{
					cout << "-" << i->getName() << endl;
					playerInventory.push_back(i);
				}
				pCurrentLocation->removeItems();
			}
			pauseAndFlush();
			continue; //Restarts the loop without changing location after investigating.
		}
		//A new location pointer based on user input
		Location* chosenLocation = pCurrentLocation->getConnection(userInput - 1);

		if (pCurrentLocation->isLocked(userInput - 1))
		{
			if (!pCurrentLocation->unlockDoor(userInput - 1, playerInventory)) {
				cout << "The door is locked - you cannot open it!" << endl;
				pauseAndFlush();
				continue; //Restarts the loop without changing location after failed attempt to unlock.
			}
		}
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

// Pauses the program and waits for user input before continuing
void pauseAndFlush()
{
	cout << endl;
	system("pause");
}

void pauseAndWipe()
{
	cout << endl;
	system("pause");
	system("cls");
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