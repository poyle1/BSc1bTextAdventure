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
		enum questStates
		{
			Unknown,
			Aware,
			Accepted,
			Achieved,
			Completed,
			Failed
		};
		enum questResult
		{
			Incomplete,
			Good,
			Neutral,
			Bad
		};

	private:
		std::string m_questName;
		std::string m_questDescription;
		questStates m_state = Unknown;
		questResult m_result = Incomplete;
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

		questStates getState() const;
		void advanceState(questStates nState, Player& nPlayer);
		bool isFailed() const;
		questResult getResult() const;
		void setResult(questResult nResult);

		/*void addObjective(std::string objectiveName, std::string objectiveDescription);
		void objectiveCompleted(std::string objectiveName);
		void outputObjectives() const;*/

		void currentQuestInfo(Player& nPlayer) const; 
		void resetQuest(Player& nPlayer);
	};
}