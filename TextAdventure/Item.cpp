#include "Item.h"
#include <string>
#include "Key.h"

Item::Item()
{
	m_name = "An item";
	m_description = "This is an item.";
	m_ingredient = false;
}

Item::Item(string nName, string nDescription, bool isIng)
{
	m_name = nName;
	m_description = nDescription;
	m_ingredient = isIng;
}

bool Item::isIngredient()
{
	return m_ingredient;
}

string Item::getName()
{
	return m_name;
}

string Item::getDescription()
{
	return m_description;
}

void Item::setName(string nName)
{
	m_name = nName;
}

void Item::setDescription(string nDesc)
{
	m_description = nDesc;
}

string Item::toString()
{
	return m_name + "." + m_description;
}

string Item::getKeyID()
{
	return "";
}

