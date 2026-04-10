#pragma once
#include <string>
#include "Player.h"

namespace GameObject
{
	class Player;
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

		//Basic Getters and setters//
		std::string getQuestName() const;
		void setQuestName(std::string nName);
		std::string getQuestDescription() const;
		void setQuestDescription(std::string nDesc);

		//Quest state logic//
		QuestStates getState() const;
		void advanceState(QuestStates nState, Player& nPlayer);
		bool isFailed() const;

		//Objective logic//
		void addObjective(std::string objectiveName, std::string objectiveDescription);
		void objectiveCompleted(std::string objectiveName);
		void outputObjectives() const;
	};
}