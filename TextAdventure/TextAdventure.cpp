#include <iostream>
#include <string>
#include <vector>
#include "Location.h"
#include <windows.h>

using namespace std;

void gameIntro();
void titleScreen();
void pauseAndFlush();
void asciiArt(Location& pCurrentLocation);

int main()
{
	// Maximize console window on startol
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	Location loc1("Forest Path", "A winding path flows through pine, oak, and fir. At the end lies a stone wall, leading to the church courtyard.");
	Location loc2("Church Courtyard", "The courtyard is littered with heaps of tree debris. Broken headstones jut from the ground at odd angles.");
	Location loc3("Ruined Church", "The church is in ruins, with collapsed walls and a crumbling roof. It is almost silent apart from the gentle tapping of branches on what remains of the stained glass windows.");
	
	loc1.setFlavorText("The church courtyard lies ahead of you, past a crumbling stone wall");
	loc2.setFlavorText("The ruined church looms ahead; its silhouette reminds you of shards of broken glass.");
	loc3.setFlavorText("Debris litters the floor; sunlight streams through gaps in the roof, lading on the alter at the end of the hall.");

	loc1.addConnection(&loc2);
	loc2.addConnection(&loc1);
	loc2.addConnection(&loc3);
	loc3.addConnection(&loc2);


	Location* pCurrentLocation = &loc1;

	//gameIntro();
	//titleScreen();

	string input;


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
		for (int i = 0; i < pCurrentLocation->getNumConnections(); i++) {
			cout << i + 1 << ")" << pCurrentLocation->getConnection(i)->getName() << ".\n";
		}

		pCurrentLocation->outputConnections();

		cout << "====================================================================================================\n\n";

		cout << "Input: ";
		cin >> input;
		cout << endl;

		if (pCurrentLocation == &loc1)
		{
			if (input == "0")
			{
				cout << pCurrentLocation->getFlavorText() << endl;
				pauseAndFlush();
			}
			else if (input == "2")
			{
				cout << "You enter the church courtyard, stepping over fallen branches and leaves.\n";
				cout << "There is a stillness in the air, broken only by the ebb and flow of rustling trees.\n";
				pauseAndFlush();
				pCurrentLocation = &loc2;
			}
			else if (input == "3")
			{
				cout << "You can't reach the church from where you are." << endl;
				pauseAndFlush();
			}
		}
		else if (pCurrentLocation == &loc2)
		{
			if (input == "1")
			{
				cout << "You return to the forest path; wind and birdsong flow around you.\n";
				cout << "You still have secrets to uncover.\n";
				pauseAndFlush();
				pCurrentLocation = &loc1;
			}
			else if (input == "2")
			{
				cout << "You are already in the Church Courtyard.\n";
				cout << "";
				pauseAndFlush();
			}
			else if (input == "3")
			{
				cout << "You push open what is left of the door and step into the ruined church.\n";
				cout << "sticks and loose bricks litter the floor. At the end of the hall you see an alter, mostly intact.\n";
				pauseAndFlush();
				pCurrentLocation = &loc3;
			}
		}
		else if (pCurrentLocation == &loc3)
		{
			if (input == "1")
			{
				cout << "You cannot reach the forest path from here.\n";
				pauseAndFlush();
			}
			else if (input == "2")
			{
				cout << "Parts of the door flake aways as you push it open, stepping back into the church courtyard.\n";
				cout << "There is a moment of stillness as you return outside, as if the trees were waiting for you.\n";
				pauseAndFlush();
				pCurrentLocation = &loc2;
			}
			else if (input == "3")
			{
				cout << "You are already in the Ruined Church.\n";
				cout << ".\n";
				pauseAndFlush();
			}
		}
		else

			return 0;
	}

	return 0;

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

