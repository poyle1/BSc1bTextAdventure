#pragma once
#include <map>
#include <string>
namespace MilkAndSugar::Core 
{
	class Quest
	{
	public:
		enum QuestStates
		{
			Unknown,
			Aware,
			Accepted,
			Achieved,
			Completed,
			Failed
		};

	private:
		std::string m_questName;
		QuestStates m_state = Unknown;

	public:
		Quest();
		QuestStates getState() const;
		void advanceState(QuestStates newState);
		bool isFailed() const;
	};
}