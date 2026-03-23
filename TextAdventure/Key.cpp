#include <string>
#include "Key.h"
#include "Item.h"

Key::Key()
{
	m_name = "A key";
	m_description = "This is a key.";
	m_isKey = false;
	m_keyID = "";
	m_ingredient = false;
}

Key::Key(string nName, string nDescription, bool nIsKey, string nKeyID) : Item(nName, nDescription, false)
{
	m_isKey = nIsKey;
	m_keyID = nKeyID;
}

string Key::getKeyID()
{
	return m_keyID;
}

string Key::toString()
{
	return m_name + "! Maybe it opens the door to the " + m_keyID;
}
