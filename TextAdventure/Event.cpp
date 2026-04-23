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
	bool Event::canStartEvent(Player& nPlayer) const
	{
		if (!m_requirement)
		{
			return true;
		}
		else
		{
			if (nPlayer.getInventory().getItemAmount(m_eventRequirements.itemName) < m_eventRequirements.amount)
			{
				if (m_eventRequirements.amount == 1)
				{
					std::cout << "You need: '" << m_eventRequirements.itemName << "' to continue!" << std::endl;
				}
				else
				{
					std::cout << "You need " << m_eventRequirements.amount << " " << m_eventRequirements.itemName << "s" << std::endl;
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

	void Event::eventFunction(RecipeBuilder& nRecipe, Player& nPlayer, Quest& nQuest)
	{

	}
}