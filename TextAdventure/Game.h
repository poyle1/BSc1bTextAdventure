#pragma once
#include "Text.h"
class Game
{
public:
	void run();
	void mainMenu();
	void displayRules();
private:
	Text ui;
	bool isRunning;
};

