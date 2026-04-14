#pragma once
#include <string>
#include <iostream>
#include <map>

namespace GameObject 
{
	class Player;
}

namespace UI
{
	class Text
	{
	private:
		Text() {}
		static Text m_Instance;
		static std::map<std::string, std::string>& getMap();

	 public:
		static Text& getInstance();

		void loadArtLibrary(std::string fileName);
		void printArt(std::string artName);

		void printDialogue(std::string artName, std::string dialogue);
		void gameIntro();
		void dialogueBox(std::string nCharacter, std::string nArtName);
		void johnDialogue1(const GameObject::Player& nPlayer);
		void johnDialogue2(const GameObject::Player& nPlayer);
		void johnDialogueBadEnding(const GameObject::Player& nPlayer);
		void johnDialogueNeutralEnding(const GameObject::Player& nPlayer);
		void johnDialogueGoodEnding(const GameObject::Player& nPlayer);
		void lineBreak();
		void lineSpace();
	};
};