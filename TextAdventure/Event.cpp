#include "Event.h"

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
	Event::Event()
	{
		m_functionID = "zero";
		m_name = "Default Event";
		m_prompt = "Start the event";
		m_completed = false;

		m_requirement = false;
		m_eventRequirements.itemName;
		m_eventRequirements.amount = 0;
		m_eventRequirements.collected = false;
	}
	Event::Event(std::string nID, std::string nName, std::string nPrompt, bool nReq)
	{
		m_functionID = nID;
		m_name = nName;
		m_prompt = nPrompt;
		m_completed = false;

		m_requirement = nReq;
		m_eventRequirements.itemName;
		m_eventRequirements.amount = 0;
		m_eventRequirements.collected = false;
	}
	Event::Event(std::string nID, std::string nName, std::string nPrompt, bool nReq, std::string nRequItemName, int nRequItemAmount)
	{
		m_functionID = nID;
		m_name = nName;
		m_prompt = nPrompt;
		m_completed = false;

		m_requirement = nReq;
		m_eventRequirements.itemName = nRequItemName;
		m_eventRequirements.amount = nRequItemAmount;
		m_eventRequirements.collected = false;
	}
	std::string Event::getName() const
	{
		return m_name;
	}
	void Event::setName(std::string nName)
	{
		m_name = nName;
	}
	std::string Event::getPrompt() const
	{
		return m_prompt;
	}
	void Event::setPrompt(std::string nPrompt)
	{
		m_prompt = nPrompt;
	}
	bool Event::isCompleted() const
	{
		return m_completed;
	}
	void Event::setCompleted(bool nCompleted)
	{
		m_completed = nCompleted;
	}
	bool Event::hasRequirement() const
	{
		return m_requirement;
	}
	std::string Event::getReqItemName() const
	{
		return m_eventRequirements.itemName;
	}
	void Event::setReqItemName(std::string nName)
	{
		m_eventRequirements.itemName = nName;
	}
	int Event::getReqItemAmount() const
	{
		return m_eventRequirements.amount;
	}
	void Event::setReqItemAmount(int nAmount)
	{
		m_eventRequirements.amount = nAmount;
	}
	bool Event::getCollected() const
	{
		return m_eventRequirements.collected;
	}
	void Event::setCollected(bool nCollected)
	{
		m_eventRequirements.collected = nCollected;
	}
	bool Event::canStartEvent(Player& nPlayer, std::string nItem) const
	{
		if (!m_requirement)
		{
			return true;
		}
		else
		{
			if (nPlayer.getInventory().getItemAmount(nItem) < m_eventRequirements.amount)
			{
				if (m_eventRequirements.amount == 1)
				{
					std::cout << "You need: '" << nItem << "' to continue!" << std::endl;
				}
				else
				{
					std::cout << "You need " << m_eventRequirements.amount << " " << nItem << "s" << std::endl;
				}
				UI::pauseAndFlush();
				return false;
			}
			else
			{
				return true;
			}
		}
	}
	void Event::runFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{
		if (!canStartEvent(nPlayer, getReqItemName()))
		{
			return;
		}

		if (m_functionID == "JOHN")
		{
			talkToJohn(nPlayer, nQuest);
		}
		else if (m_functionID == "TEA")
		{
			teaBuilder(nRecipe, nPlayer, nQuest);
		}
		else if (m_functionID == "SINK")
		{
			fillKettle(nPlayer);
		}
		else
		{
			std::cout << "Nothing happens." << std::endl;
			UI::pauseAndFlush();
		}
	}
	//Starts the RecipeBuilder minigame if the player has quest items >= the
	// amount of steps in the recipe. It then advances the quest state.
	void Event::teaBuilder(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{
		if (!nPlayer.getInventory().hasReqQuestItems(nRecipe.getRecipeSteps()))
		{
			std::cout << "You have " << nPlayer.getInventory().getQuestItemTotal() << " out of " << nRecipe.getRecipeSteps() << " ingredients!" << std::endl;
			std::cout << "Collect them all to start making: " << nRecipe.getName() << "." << std::endl;
			UI::pauseAndFlush();
			return;
		}
		nQuest.advanceState(Quest::Achieved, nPlayer);
		nRecipe.teaBuilderMkII(nPlayer, nQuest);
		return;
	}

	void Event::talkToJohn(Player& nPlayer, Quest& nQuest)
	{
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
	void Event::fillKettle(Player& nPlayer)
	{
		if (nPlayer.getInventory().getItemViaName("Empty Kettle"))
		{
			std::cout << "You fill up the kettle with water!" << std::endl;
			nPlayer.getInventory().getItemViaName("Empty Kettle")->setName("Filled Kettle");
			nPlayer.getInventory().getItemViaName("Filled Kettle")->setQuestItem(true);
			UI::pauseAndFlush();
		}
		else
		{
			return;
		}
	}
}