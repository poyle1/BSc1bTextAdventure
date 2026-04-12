#pragma once
#include <string>
#include <iostream>

namespace GameObject
{
	class Player;
}
namespace UI {
	class Text;
}

namespace GameObject 
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
		std::string m_questDescription;
		QuestStates m_state = Unknown;
		struct QuestObjectiveInfo
		{
			std::string objectiveName;
			std::string objectiveDescription;
			bool completed;
		};

	public:
		Quest();
		Quest(std::string nName, std::string nDesc);

		std::string getQuestName() const;
		void setQuestName(std::string nName);
		std::string getQuestDescription() const;
		void setQuestDescription(std::string nDesc);

		QuestStates getState() const;
		void advanceState(QuestStates nState, Player& nPlayer);
		bool isFailed() const;

		/*void addObjective(std::string objectiveName, std::string objectiveDescription);
		void objectiveCompleted(std::string objectiveName);
		void outputObjectives() const;*/

		void currentQuestInfo(Player& nPlayer) const; 
	};
}