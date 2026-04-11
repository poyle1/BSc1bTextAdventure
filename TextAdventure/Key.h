#pragma once
#include "Item.h"

#include <string>

namespace GameObject
{
	class Key : public Item
	{
	private:
		bool m_isKey;
		std::string m_keyID;

	public:
		Key();
		Key(std::string nName, std::string nDescription, bool nIsKey, std::string nKeyID);

		std::string toString() override;
		std::string getKeyID() override;
	};
}