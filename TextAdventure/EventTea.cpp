#include "EventTea.h"

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
	EventTea::EventTea()
	{
		m_functionID = "2";
		m_name = "Tea";
		m_prompt = "Make a cup of tea";
		m_completed = false;
		m_requirement = false;
		m_eventRequirements.itemName;
		m_eventRequirements.amount = 0;
		m_eventRequirements.collected = false;
	}
	EventTea::EventTea(std::string nID, std::string nName, std::string nPrompt, bool nReq, std::string nRequItemName, int nRequItemAmount)
		: Event(nID, nName, nPrompt, nReq, nRequItemName, nRequItemAmount)
	{

	}

	void EventTea::eventFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{
		if (m_completed)
		{
			std::cout << "You have already made a cup of tea for John." << std::endl;
			std::cout << "Bring him the tea before it gets cold!" << std::endl;
			UI::pauseAndFlush();
			return;
		}
		if (!nPlayer.getInventory().hasReqQuestItems(nRecipe.getRecipeSteps()))
		{
			std::cout << "You have " << nPlayer.getInventory().getQuestItemTotal() << " out of " << nRecipe.getRecipeSteps() << " ingredients!" << std::endl;
			std::cout << "Collect them all to start making: " << nRecipe.getName() << "." << std::endl;
			UI::pauseAndFlush();
			return;
		}
		nQuest.advanceState(Quest::Achieved, nPlayer);
		nRecipe.teaBuilderMkII(nPlayer, nQuest);
		m_completed = true;
		return;
	}
}