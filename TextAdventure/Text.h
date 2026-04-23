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
		void printArt(std::string artName) const;

		void printDialogue(std::string artName, std::string dialogue) const;
		void gameIntro() const;
		void dialogueBox(std::string nCharacter, std::string nArtName) const;
		void johnDialogue1(const GameObject::Player& nPlayer) const;
		void johnDialogue2(const GameObject::Player& nPlayer) const;
		void johnDialogueBadEnding(const GameObject::Player& nPlayer) const;
		void johnDialogueNeutralEnding(const GameObject::Player& nPlayer) const;
		void johnDialogueGoodEnding(const GameObject::Player& nPlayer) const;
		void lineBreak() const;
		void lineSpace() const;
	};
};