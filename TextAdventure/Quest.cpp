#include "Quest.h"
#include "Common.h"

namespace MilkAndSugar::Core {
Quest::Quest()
{
	m_state = Unknown;
	m_failed = false;
}
Core::Quest::QuestState Quest::getState()
{
	return m_state;
}
void Quest::setState(QuestState newState)
{
	m_state = newState;
}
void Quest::advanceState()
{
	if (m_failed == true || m_state == Completed)
	{
		return; //Can't advance if the quest is already failed or completed
	}
	m_state = static_cast<QuestState>(static_cast<int>(m_state) + 1); //Advance to the next state in the enum
}
bool Quest::isFailed() const
{
	return m_failed;
}
void Quest::setFailed()
{
	m_failed = true;
	m_state = Failed;
}
}