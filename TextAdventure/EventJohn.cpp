#include "EventJohn.h"

#include <string>
#include <iostream>

#include "Utility.h"
#include "RecipeBuilder.h"
#include "Text.h"
#include "Player.h"
#include "Quest.h"
#include "Inventory.h"

namespace GameObject
{
	EventJohn::EventJohn()
	{
		m_functionID = "0";
		m_name = "John";
		m_prompt = "Talk to John";

		m_requirement = false;
		m_eventRequirements.itemName;
		m_eventRequirements.amount = 0;
		m_eventRequirements.collected = false;
	}
	EventJohn::EventJohn(std::string nID, std::string nName, std::string nPrompt, bool nReq, std::string nRequItemName, int nRequItemAmount)
		: Event(nID, nName, nPrompt, nReq, nRequItemName, nRequItemAmount)
	{
		
	}

	void EventJohn::eventFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{
		if (!canStartEvent(nPlayer))
		{
			return;
		}
		Quest::questStates state = nQuest.getState();

		if (state == Quest::Unknown)
		{
			UI::Text::getInstance().johnDialogue1(nPlayer);
			nQuest.advanceState(Quest::Accepted, nPlayer);
			UI::pauseAndFlush();
		}
		else if (state == Quest::Accepted)
		{
			UI::Text::getInstance().johnDialogue2(nPlayer);
			UI::pauseAndFlush();
		}
		else if (state == Quest::Achieved)
		{
			Item* tea = nPlayer.getInventory().getItemViaName("Cup of Tea");

			if (tea == nullptr) //Safety check
			{
				std::cout << "ERROR - TEA NAME MISSMATCH" << std::endl;
				return;
			}
			std::cout << "You pass the tea over to John." << std::endl;
			int score = tea->getScoreValue();
			if (score <= 15) //Bad ending, 15 or less score
			{
				UI::Text::getInstance().johnDialogueBadEnding(nPlayer);
				nQuest.setResult(Quest::Bad);
			}
			else if (score < 19) //Neutral Ending, between 15-19 score	
			{
				UI::Text::getInstance().johnDialogueNeutralEnding(nPlayer);
				nQuest.setResult(Quest::Neutral);
			}
			else //Good Ending, 19-30 score
			{
				UI::Text::getInstance().johnDialogueGoodEnding(nPlayer);
				nQuest.setResult(Quest::Good);
			}
			nQuest.advanceState(Quest::Completed, nPlayer);
			UI::pauseAndFlush();
		}
	}
}