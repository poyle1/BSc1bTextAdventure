#include <string>
#include "Key.h"
#include "Item.h"

Key::Key()
{
	m_name = "A key";
	m_description = "This is a key.";
	m_isKey = false;
	m_keyID = "";
	m_questItem = false;
}

Key::Key(std::string nName, std::string nDescription, bool nIsKey, std::string nKeyID) : Item(nName, nDescription, false)
{
	m_isKey = nIsKey;
	m_keyID = nKeyID;
}

std::string Key::getKeyID()
{
	return m_keyID;
}

std::string Key::toString()
{
	return m_name + "! Maybe it opens the door to the " + m_keyID;
}
