#include "Text.h"
#include "Utility.h"
#include <iostream> //cout
#include <fstream> // ifstream and ofstream
#include <string> // getline

using namespace Utility;
using namespace std;

void Text::printArt(string artName)
{
	ifstream artFile("./Data/asciiAssets.txt");
	string artLine;
	bool found = false;

	string searchTag = "[" + artName + "]";

	while (getline(artFile, artLine))
	{
		if (artLine == searchTag)
		{
			found = true;
			continue; //Skips the line where the searchTag is found
		}
		if (found)
		{
			if (artLine.size() > 0 && artLine[0] == '[')
			{
				break; //Stops printing if the next search tag is hit
			}
			cout << artLine << endl;
		}
	}
	if (!found) {
		cout << "Art[" << artName << "] not found." << endl;
	}
	artFile.close();
}

void Text::printDialogue(string artName, string dialogue)
{
	system("cls");
	printArt(artName); //Draw ASCII art
	cout << dialogue << endl << endl; //Print dialogue
	system("pause");
}

void Text::gameIntro()
{
	printDialogue("INTRO", "\"Hello!\"");
	printDialogue("INTRO", "\"Thank you for popping round.\"");
	printDialogue("INTRO", "\"I get very lonely sometimes...\"");
	printDialogue("INTRO", "\"...\"");
	printDialogue("INTRO", "\"Would you like me to tell you a story?\"");
	printDialogue("INTRO", "\"Its about history!\"");
	printDialogue("INTRO", "\"Lost history...\"");
	printDialogue("INTRO", "\"But first, can you make me a cup of tea?\"");
}
