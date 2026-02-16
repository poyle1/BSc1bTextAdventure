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

//TO ADD
//A bool in the Location class to check if visited
// 
//A function to output text when returning to a previously visited location
//use the bool to check if visited
//If visited, output different text
//
//Add player class (Compare to player class from previous project)
//Expand item class (Items are equivalent to cards from previous project)
//Incorporate items to player class
//Incorporate items into locations
//Expand Monster class
//Incorporate monsters into locations
//Incorporate combat system between player and monsters
//Monsters drop items when defeated, feeding into player inventory via player class
//Inventory system as a vector in the player class (equivalent to a players deck of cards from previous project)
//
//Current location text should greater reflect the current location, instead of what is around it
//
//MOSCOW METHOD
//
//Read CVS file to load locations, items, monsters.


int main()
{
	// Maximize console window on start
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	gameIntro();
	titleScreen();

	
	Location livingRoom("Living Room", false);
	Location hallWay("Hallway", false);
	Location bedroom("Bedroom", true);

	livingRoom.addConnection(&hallWay);
	hallWay.addConnection(&livingRoom);
	hallWay.addConnection(&bedroom);
	bedroom.addConnection(&hallWay);

	


	Location* pCurrentLocation = &livingRoom;

	while (true)
	{
		system("cls");



		//Ascii art & line breaks are 100 characters wide
		cout << "====================================================================================================\n";
		cout << "Current location: " << pCurrentLocation->getName() << "\n";
		cout << "====================================================================================================\n";
		asciiArt(*pCurrentLocation);
		cout << "====================================================================================================\n";
		cout << "Enter a number to go to a location:\n";
		cout << "Or enter '0' to learn more about your current location.\n\n";
		
		cout << "Available Locations:" << "\n";
		pCurrentLocation->outputConnections();
		cout << "====================================================================================================\n\n";

		//User Input is recieved and stored
		//Selected index is user input - 1 to match vector index
		//Having 2 variables has clearer distinction instead of sharing one variable
		//Also allows for easier error checking
		int userInput;
		cout << "Input: ";
		cin >> userInput;
		int selectedIndex = userInput - 1;
		cout << endl;

		//Invalid input check
		if (selectedIndex < 1 || selectedIndex >= pCurrentLocation->getNumConnections()) {
			cout << "Invalid input. Please enter a number to travel to a listed location." << endl;
			pauseAndFlush();
			continue;
		}
		//Move to selected location
		//Another if statement is not needed here due to prior error checking
		//Selected index will always be valid at this point
		pCurrentLocation = pCurrentLocation->getConnection(selectedIndex);
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
		cout << "\".....................................=%+++++++++++++++++++++++++++++++++++++++++++%@#++++++++*%%%*+++++\\n\"\n"
			"\".....................................=%++++++++++++++++++++++++++++++++++++++++++@%++++++++++++*%%*++++\\n\"\n"
			"\"-------------------------------------------------------------------------------------------------------\"" << endl;
	}
	else if (currentLocation.getName() == "Ruined Church") {
		cout << "---------@*......@@-......@@----------------------------------------------+@=........%@........@@------\n"
			"---------@*......:@=......@@-----------------------------------------------@@.........@+.......@@------\n"
			"--------%@@@@@@@@@@@@@@@@@@@=----------------------------------------------%@.........@+.......-@*-----\n"
			"--------%@.......:@=......@@-----------------------------------------------%@...:-----@*---..--+@*-----\n"
			"----------------------------------=#*----@@###################%@=--------------------------------------\n"
			"-----------------------------------------@@###################%@=--------------------------------------" << endl;
	}
}

// Displays the entry text of the location when the player enters it
//
void enterLocation(Location* loc)
{
	cout << "You have entered the " << loc->getName() << "." << endl;
	pauseAndFlush();
}

