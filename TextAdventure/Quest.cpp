#include "Quest.h"

#include <string>
#include <iostream>

#include "Text.h"
#include "Player.h"

namespace GameObject {
	Quest::Quest()
	{
		m_questName = "Default Quest";
		m_questDescription = "This is a default quest description.";
		m_state = Unknown;
		m_result = Incomplete;
	}
	Quest::Quest(std::string nName, std::string nDesc)
	{
		m_questName = nName;
		m_questDescription = nDesc;
		m_state = Unknown;
		m_result = Incomplete;
	}
	
	std::string Quest::getQuestName() const
	{
		return m_questName;
	}

	void Quest::setQuestName(std::string nName)
	{
		m_questName = nName;
	}
	std::string Quest::getQuestDescription() const
	{
		return m_questDescription;
	}
	void Quest::setQuestDescription(std::string nDesc)
	{
		m_questDescription = nDesc;
	}
	Quest::questStates Quest::getState() const
	{
		return m_state;
	}

	void Quest::advanceState(questStates nState, Player& nPlayer)
	{
		if (m_state == Failed || m_state == Completed)
		{
			return; //Can't advance if the quest is already failed or completed
		}
		if (nState <= m_state)
		{
			return; //Can't regress or stay in the same state
		}
		m_state = nState;
		if (nState == Accepted)
		{
			m_questName += " [ACTIVE]";
			nPlayer.setHasActiveQuest(true);
		}
		if (nState == Completed)
		{
			m_questName += " [COMPLETED]";
			nPlayer.setHasActiveQuest(false);
		}
		if (nState == Failed)
		{
			m_questName += " [FAILED]";
			nPlayer.setHasActiveQuest(false);
		}
	}
	bool Quest::isFailed() const
	{
		return m_state == Failed;
	}
	Quest::questResult Quest::getResult() const
	{
		return m_result;
	}
	void Quest::setResult(questResult nResult)
	{
		m_result = nResult;
	}
	void Quest::currentQuestInfo(Player& nPlayer) const
	{
		std::cout << "Quest: ";
		if (nPlayer.getHasActiveQuest())
		{
			std::cout << m_questName << " - " << m_questDescription << std::endl;
			std::cout << "Total Ingredients: " << nPlayer.getInventory().getQuestItemTotal() << std::endl;
		}
		else
		{
			std::cout << "None" << std::endl;
		}
		UI::Text::getInstance().lineBreak();
	}
}