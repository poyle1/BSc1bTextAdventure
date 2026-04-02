#include "Quest.h"
#include "Common.h"

namespace MilkAndSugar::Core {
	Quest::Quest()
	{
		m_state = Unknown;
	}
	Quest::QuestStates Quest::getState() const
	{
		return m_state;
	}

	void Quest::advanceState(QuestStates newState)
	{
		if (m_state == Failed || m_state == Completed)
		{
			return; //Can't advance if the quest is already failed or completed
		}
		if (newState <= m_state)
		{
			return; //Can't regress or stay in the same state
		}
		m_state = newState;
	}

	bool Quest::isFailed() const
	{
		return m_state == Failed;
	}
}