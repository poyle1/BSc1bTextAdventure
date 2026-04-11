#include "Item.h"

#include <string>

namespace GameObject
{
	Item::Item()
	{
		m_name = "An item";
		m_description = "This is an item.";
		m_questItem = false;
	}

	Item::Item(std::string nName, std::string nDescription, bool isQuest)
	{
		m_name = nName;
		m_description = nDescription;
		m_questItem = isQuest;
	}

	bool Item::isQuestItem()
	{
		return m_questItem;
	}

	std::string Item::getName()
	{
		return m_name;
	}

	std::string Item::getDescription()
	{
		return m_description;
	}

	void Item::setName(std::string nName)
	{
		m_name = nName;
	}

	void Item::setDescription(std::string nDesc)
	{
		m_description = nDesc;
	}

	std::string Item::toString()
	{
		return m_name + "." + m_description;
	}

	std::string Item::getKeyID()
	{
		return "";
	}
}