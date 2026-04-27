#include "EventSink.h"

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
	EventSink::EventSink()
	{
		m_functionID = "4";
		m_name = "sink";
		m_prompt = "Use the sink";

		m_requirement = true;
		m_eventRequirements.itemName = "Empty Kettle";
		m_eventRequirements.amount = 1;
		m_eventRequirements.collected = false;
	}
	EventSink::EventSink(std::string nID, std::string nName, std::string nPrompt, bool nReq, std::string nRequItemName, int nRequItemAmount)
		: Event(nID, nName, nPrompt, nReq, nRequItemName, nRequItemAmount)
	{

	}

	void EventSink::eventFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{
		if (m_completed)
		{
			std::cout << "You've already filled up the kettle with water!" << std::endl;
			UI::pauseAndFlush();
			return;
		}
		Item* kettle = nPlayer.getInventory().getItemViaName(m_eventRequirements.itemName);

		if (kettle != nullptr) //safety check
		{
			std::cout << "You fill up the kettle with water!" << std::endl;
			kettle->setName("Filled Kettle");
			kettle->setQuestItem(true);
			m_completed = true;
			UI::pauseAndFlush();
		}
		else
		{
			std::cout << "You turn the tap on and water flows through." << std::endl;
			std::cout << "You may be able to fill up an empty container here..." << std::endl;
			UI::pauseAndFlush();
		}
	}
}