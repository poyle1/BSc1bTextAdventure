#pragma once
#include <map>
namespace MilkAndSugar::Core {
class Quest
{
private:
	enum state
	{
		Unknown,
		Aware,
		Accepted,
		Achieved,
		Completed,
		Failed
	};

	std::map<int, state> QuestState; // Fixed the error by replacing 'enum' with 'QuestState1'

	QuestState1 m_state;
	bool m_failed;
	

public:
	Quest();
	QuestState1 getState();
	void setState(QuestState1 newState);
	void advanceState();

	bool isFailed() const;
	void setFailed();
};
}