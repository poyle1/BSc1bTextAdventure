#include "Text.h"

#include <iostream>
#include <fstream>
#include <string>

#include "Utility.h"
#include "Player.h"

namespace UI
{
	Text Text::m_Instance;

	std::map<std::string, std::string>& Text::getMap()
	{
		static std::map<std::string, std::string> artLibrary;
		return artLibrary;
	}
	Text& Text::getInstance()
	{
		return m_Instance;
	}

	void Text::loadArtLibrary(std::string fileName)
	{
		std::ifstream artFile(fileName);
		auto& artLibrary = getMap();
		if (!artFile.is_open())
		{
			std::cout << "Error, could not find file " << fileName << std::endl;
			return;
		}

		std::string artLine;
		std::string searchTag = "";
		std::string artBlock = "";

		while (getline(artFile, artLine))
		{
			//Detect Tag
			if (!artLine.empty() && artLine.front() == '[' && artLine.back() == ']')
			{
				//If a tag is in progress, add it to the library before moving on to the next tag
				if (!searchTag.empty()) //safety check
				{
					//makes a new entry
					artLibrary[searchTag] = artBlock;
				}
				
				//Start new tag
				searchTag = artLine.substr(1, artLine.size() - 2);
				artBlock = "";
			
			}
			else if (!searchTag.empty())
			{
				artBlock += artLine + "\n";
			}
		}

		if (!searchTag.empty())
		{
			artLibrary[searchTag] = artBlock;
		}
		artFile.close();
	}

	void Text::printArt(std::string artName)
	{
		auto& artLibrary = getMap();
		if (artLibrary.count(artName))
		{
			std::cout << artLibrary[artName];
		}
		else
		{
			std::cout << "Error: Art " << artName << " not found in library." << std::endl;
		}
	}

	void Text::printDialogue(std::string artName, std::string dialogue)
	{
		system("cls");
		printArt(artName); //Draw ASCII art
		std::cout << dialogue << std::endl << std::endl; //Print dialogue
		system("pause");
	}

	void Text::gameIntro()
	{
		//introArtFrame1
		//introArtFrame2
		//introArtFrame3
		//Then the game starts
	}

	void Text::dialogueBox(std::string nCharacter, std::string nArtName)
	{
		system("cls");
		lineBreak();
		std::cout << nCharacter << std::endl;
		lineBreak();
		printArt(nArtName);
		lineBreak();
		lineSpace();
	}

	void Text::johnDialogue1(const GameObject::Player& nPlayer)
	{
		dialogueBox("John", "JOHN");
		std::cout << "John: \"Oh hello " << nPlayer.getName() << "!\"" << std::endl;
		std::cout << "John: \"I'm glad you're here - I was getting a bit bored on my own.\"" << std::endl;
		std::cout << "John: \"I was just about to make myself a tea, but I've unpacked the shopping in a VERY strange way...\"" << std::endl;
		std::cout << "John: \"Please could you have a look around and make me a tea once you have everything?\"" << std::endl;
	}
	void Text::johnDialogue2(const GameObject::Player& nPlayer)
	{
		dialogueBox("John", "JOHN");
		std::cout << "\"How's that tea coming along, " << nPlayer.getName() << "?\"" << std::endl;
		std::cout << "\"The house is a bit of a mess, but you should be able to find what you need if you look around.\"" << std::endl;
		std::cout << "\"There is a key somewhere in here for my bedroom. I think I left the sugar in there...\"" << std::endl;
	}
	
	void Text::johnDialogueBadEnding(const GameObject::Player& nPlayer)
	{
		dialogueBox("John", "JOHN");
		std::cout << "John: \"Oh thank you" << nPlayer.getName() << "! This is just what I needed.\"" << std::endl;
		std::cout << "John: *sips*" << std::endl;
		std::cout << "John: *...*" << std::endl;
		std::cout << "John: *sips*..." << std::endl;
		UI::pauseAndFlush;
		std::cout << "John falls to the floor." << std::endl;
	}
	void Text::johnDialogueNeutralEnding(const GameObject::Player& nPlayer)
	{
		dialogueBox("John", "JOHN");
		std::cout << "John: \"Oh thank you" << nPlayer.getName() << "! This is just what I needed.\"" << std::endl;
		std::cout << "John: *sips*" << std::endl;
		std::cout << "John: *...*" << std::endl;
		std::cout << "John: *sips*" << std::endl;
		std::cout << "John: \"Umm...Thanks... Yeah, this is good, thanks...\"" << std::endl;
		UI::pauseAndFlush;
		std::cout << "John: \"....Hmm, whats that?\"" << std::endl;
		std::cout << "John: \"Oh yeah, I suppose I'll tell you about a tale of lost histories then.\"" << std::endl;
	}
	void Text::johnDialogueGoodEnding(const GameObject::Player& nPlayer)
	{
		dialogueBox("John", "JOHN");
		std::cout << "John: \"Oh thank you" << nPlayer.getName() << "! This is just what I needed.\"" << std::endl;
		std::cout << "John: *sips*" << std::endl;
		std::cout << "John: *...*" << std::endl;
		std::cout << "John: *blows*" << std::endl;
		std::cout << "John: *sips*" << std::endl;
		std::cout << "John: \"Thats lovely, great stuff.\"" << std::endl;
		UI::pauseAndFlush;
		std::cout << "John: \"Now then, let me tell you all about a tale of lost histories!\"" << std::endl;
	}
	void Text::lineBreak()
	{
		std::cout << "====================================================================================================\n";
	}
	void Text::lineSpace()
	{
		std::cout << std::endl;
	}
}