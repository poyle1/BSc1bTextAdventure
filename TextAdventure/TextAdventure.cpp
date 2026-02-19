#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

#include "Location.h"
#include "Item.h"
#include "EdibleItem.h"
#include "WeaponItem.h"
#include "DefenceItem.h"
#include "Inventory.h"
#include "Player.h"
#include "BasicEnemy.h"

using namespace std;

void gameIntro();
void acsii1();
void titleScreen();
void pauseAndFlush();
void pauseAndWipe();
void asciiArt(Location& pCurrentLocation);
void enterLocation(Location* nloc);
int getValidIntInput(int min, int max);

int main()
{
	//Maximize console window on start
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); //Maximize the console window on start for better visibility of the ASCII art and game text
	SetConsoleOutputCP(CP_UTF8); //Enable UTF-8 encoding for console output to support extended ASCII characters in the art

	//gameIntro();
	//titleScreen();

	
	Location livingRoom("Living Room", false);
	Location hallWay("Hallway", false);
	Location bedroom("Bedroom", true);
	livingRoom.setInspectText("This is the living room.");
	hallWay.setInspectText("This is the hallway.");
	bedroom.setInspectText("This is the bedroom.");

	livingRoom.addConnection(&hallWay);
	hallWay.addConnection(&livingRoom);
	hallWay.addConnection(&bedroom);
	bedroom.addConnection(&hallWay);

	Item bedroomKey("Bedroom Key");
	Item sugar("Sugar");
	livingRoom.addItem(&bedroomKey);
	livingRoom.addItem(&sugar);


	Location* pCurrentLocation = &livingRoom;

	vector<Item*> playerInventory = {};

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
			pauseAndFlush();

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
			continue;
		}

		//Pointer to the location selected by the user, used to change the current location pointer
		Location* chosenLocation = pCurrentLocation->getConnection(userInput - 1);

		if (chosenLocation->isLocked())
		{
			if (chosenLocation->getName() == "Bedroom" && find(playerInventory.begin(), playerInventory.end(), &bedroomKey) != playerInventory.end())
			{
				cout << "You use the Bedroom Key to unlock the door." << endl;
				chosenLocation->unlock();
				pauseAndFlush();
				break;
			}
			cout << "The door is locked and you cannot open it!" << endl;
			pauseAndFlush();
			continue; //restart the loop without changing location
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

int getValidIntInput(int min, int max)
{
	int userInput;

	while (true)
	{
		cout << "Input: ";
		cin >> userInput;

		if (!cin.fail() && userInput >= min && userInput <= max)
		{
			return userInput;
		}
		else
		{
			cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
			cin.clear(); // Clear the error flag
			cin.ignore(1000, '\n'); // Discard invalid input
		}
	}
}