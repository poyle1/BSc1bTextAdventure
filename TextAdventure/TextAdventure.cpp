#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include "Item.h"
#include "EdibleItem.h"
#include <windows.h>

using namespace std;

void gameIntro();
void titleScreen();
void pauseAndFlush();
void asciiArt(Location& pCurrentLocation);
void enterLocation(Location* nloc);

int main()
{
	// Maximize console window on start
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	Location loc1("Forest Path", "A winding path flows through pine, oak, and fir. At the end lies a stone wall, leading to the church courtyard.");
	Location loc2("Church Courtyard", "The courtyard is littered with heaps of tree debris. Broken headstones jut from the ground at odd angles.");
	Location loc3("Ruined Church", "The church is in ruins, with collapsed walls and a crumbling roof. It is almost silent apart from the gentle tapping of branches on what remains of the stained glass windows.");
	
	loc1.setFlavorText("The church courtyard lies ahead of you, past a crumbling stone wall.\n");
	loc1.setEntryText(".\n");
	//loc1.setReturnText("You return to the forest path; wind and birdsong flow around you.\nYou still have secrets to uncover.\n");
	
	loc2.setFlavorText("The ruined church looms ahead; its silhouette reminds you of shards of broken glass.\n");
	loc2.setEntryText("You enter the church courtyard, stepping over fallen branches and leaves.\n There is a stillness in the air, broken only by the ebb and flow of rustling trees.\n");
	//loc2.setReturnText("There is a moment of stillness as you return to the courtyard, as if the trees were waiting for you.\n");
	
	loc3.setFlavorText("Debris litters the floor; sunlight streams through gaps in the roof, lading on the alter at the end of the hall.\n");
	loc3.setEntryText("You push open what is left of the door and step into the ruined church.\nSticks and loose bricks litter the floor. At the end of the hall you see an alter, mostly intact.\n");
	//loc3.setReturnText("Parts of the door flake aways as you push it open again, stepping back into the church.\n");

	loc1.addConnection(&loc2);
	loc2.addConnection(&loc1);
	loc2.addConnection(&loc3);
	loc3.addConnection(&loc2);

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

	vector<Item> basicItemsVec = {
	Item("Old book", 1),
	Item("Brass Goblet", 5),
	Item("Gem", 10),
	};

	vector<EdibleItem> healthPotionsVec = {
	EdibleItem("Small Health Potion", 5, 10, 0),
	EdibleItem("Medium Health Potion", 10, 25, 0),
	EdibleItem("Large Health Potion", 20, 50, 0),
	};


	//item testing
	for (int i = 0; i < healthPotionsVec.size(); i++) {
		cout << healthPotionsVec[i].getName() << endl;
	}
	system("pause");
	

	Location* pCurrentLocation = &loc1;

	//gameIntro();
	//titleScreen();

	while (true)
	{
		system("cls");



		//Ascii art & line breaks are 100 characters wide
		cout << "====================================================================================================\n";
		cout << "Current location: " << pCurrentLocation->getName() << "\n";
		cout << pCurrentLocation->getDescription() << "\n";
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

		//Input 0 check - displays flavor text for the current location
		if (userInput == 0) {
			cout << pCurrentLocation->getFlavorText() << endl;
			pauseAndFlush();
			continue;
		}
		//Invalid input check
		if (selectedIndex < 0 || selectedIndex >= pCurrentLocation->getNumConnections()) {
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
	cout << "               :.:--.. .=.=.-.-   -.                 \n"
		"               -..-.=.  ::.% =.-    + -.  ..-        \n"
		"             .--+..:.: -:= +-.=%:- :--.:   :..    :  \n"
		"          =-:.+: =-..+@@.. % =.%*.  +:-= .. ::    =  \n"
		"          .--:*@:=:.+: %+-=#:.--: :.:.-=%:     .:- ..\n"
		"          .++  -#:+=:++++::%#+.:%:== @%+.....- --:   \n"
		"        ..+=..-  .-@@==+==+:*:=:+ .+++++.. :--==.+   \n"
		"       --. :..=.+---++=-*+-#%.=:#%+%--=..+*%%%::-..-.\n"
		"     -+::=.-%*@++#+++++++:+=-+++@*@+ #%@.- .- +   .- \n"
		"    :   -+.-:.==+:-+-#+@%#%%*@*#####+=-:==-:.= .. .::\n"
		" :.   ...=..=++=++==+++@@@%+***@@** .==+=::=-..+-.   \n"
		"  .= .=.: +- ...====+.=+*%++%#@%*:#: =.:.==:.  =-.:- \n"
		" ..-:. .-:-=++ :+-:-==:#%@#@@*@%*.++ :-..:=+=:::=:.:.\n"
		"    -. .-=  . :++=-+++:@+%@@#%%+%@#..=-+.++.+++:+.  .\n"
		"    :=-:=-----:  .-+-=#%#%#=%#@%%@%= --.-: :   .. :  \n"
		"         ..-. .-..-.=.%@@#@@@@@@*@@-..-.=. +- +.. . .\n"
		"      - .:+..=: +.-. :@@@@@%%#@@@%@==::-:   :+=-.    \n"
		"        ...: :     :.-%@@@@#%@@#%@@@  ..:. .-  -:.   \n"
		"                 .:   %@@@@@@@@@@@@@.  ..+..-        \n"
		"                     -@@@@@@@@@@@@@@ :               \n"
		"                     +@@@@@@@@@@@@@@                 \n"
		"                    *@@@@@@@@@@@@@@@@                \n"
		"                  +@=*@@@@@@@@@@@@@@@@=              \n"
		"               ::@*-=@@@#--@@@@@@@@@@@@@:.           \n"
		"          .###@*----%@*---@@-+@@+-=@@@@--*@##:       \n"
		"--------------------@----%----=@+------@-------------\n"
		"------------------------==-----+=--------------------\n"
		"-----------------------------------------------------\n"
		"-----------------------------------------------------" << endl;
	cout << "A canopy of trees stretches toward the horizon. Mulch compress underfoot as you trek deeper into the forest.\n"
		"After a three-day journey, you reach what is said to be your\n"
		"family's final resting place: a courtyard of cracked, overgrown\n"
		"headstones lying in the shadow of a ruined church.\n"
		"\n"
		"You have come seeking any clue that might reveal the forgotten\n"
		"history of your lineage..." << endl << endl;

	system("pause");
}

void titleScreen()
{
	system("cls");
	cout << " _____                                                                      _____ \n"
		"( ___ )--------------------------------------------------------------------( ___ )\n"
		" |   |                                                                      |   | \n"
		" |   |  ______     _                                                   _    |   | \n"
		" |   | |  ____|   | |                                                 | |   |   | \n"
		" |   | | |__   ___| |_ _ __ __ _ _ __   __ _  ___ _ __ ___   ___ _ __ | |_  |   | \n"
		" |   | |  __| / __| __| '__/ _` | '_ \\ / _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __| |   | \n"
		" |   | | |____\\__ \\ |_| | | (_| | | | | (_| |  __/ | | | | |  __/ | | | |_  |   | \n"
		" |   | |______|___/\\__|_|  \\__,_|_| |_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |   | \n"
		" |   |  / __ \\                | |       __/ |                               |   | \n"
		" |   | | |  | |_   _  ___  ___| |_     |___/                                |   | \n"
		" |   | | |  | | | | |/ _ \\/ __| __|                                         |   | \n"
		" |   | | |__| | |_| |  __/\\__ \\ |_                                          |   | \n"
		" |   |  \\___\\_\\\\__,_|\\___||___/\\__|                                         |   | \n"
		" |___|                                             By Tyler Poyle           |___| \n"
		"(_____)--------------------------------------------------------------------(_____)" << endl << endl;
	system("pause");
	cout << endl;
}

// Pauses the program and waits for user input before continuing
void pauseAndFlush()
{
	cout << endl;
	system("pause");
}

void asciiArt(Location& currentLocation) {
	if (currentLocation.getName() == "Forest Path") {
		cout << "                                                                                              .:--:.\n"
			"---..               .::..              .:--:.             .-=-:                             .:-----=\n"
			"---==----..     ..:-----=:==-:..    ..:----------:.   ..:-=--------=:.                     .--------\n"
			"----------.     .=-------------.    :-------------:.  .:-------------:                   .:---------\n"
			"-----------:  .-==--------------..:-=---------------.:-----------------.                 -----------\n"
			"------------ .-------------------:------------------=------------------:                 :---------=\n"
			"----=-----:. .-=--------=-----=-..:----------------:.:---------=------:.                  ..::::-=-=\n"
			"-===:.::..     .:=========----..   ..-:-:====--==-.. ..::.-:====:-==..                          .-==\n"
			".==-.   ..=+-....    .===.               .==-. ..::..      .:==-..-+=.....                .......===\n"
			":===..:-=+***++**=.  .===.  .::.         :==++++****=-:.   .-===-+****+**==----=---=:.    .-=======-\n"
			"-===::**************+.===.:=+**+++-..   .+************+-.  .-===************=-------:.    .-=======-\n"
			"===++******************==++**********:.=****************+..:====+*************-=----:.    .----=--==\n"
			" ...-=++++++++++++++++=::-==---------:.:----------------:.....::::::::::::::::.......           ... \n"
			"      ....::::....... ................   ..:::::::..::::...::::::......::.....:...                  \n"
			"     :::::::::::.::::::.:::::::::::::::::-::::::::::.:::::::..:..:::::.....:.....                   \n"
			"     .:::::......::..............         .::::..... ......                                         " << endl;
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
	cout << loc->getEntryText();
	pauseAndFlush();
}

