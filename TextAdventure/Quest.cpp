#include "Quest.h"

#include "Player.h"

namespace GameObject {
	Quest::Quest()
	{
		m_questName = "Default Quest";
		m_questDescription = "This is a default quest description.";
		m_state = Unknown;
	}
	Quest::Quest(std::string nName, std::string nDesc)
	{
		m_questName = nName;
		m_questDescription = nDesc;
		m_state = Unknown;
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
	Quest::QuestStates Quest::getState() const
	{
		return m_state;
	}

	void Quest::advanceState(QuestStates nState, Player& nPlayer)
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
}