#include "FreeFunctions.h"
#include <iostream>
using namespace std;

int getValidIntInput(int min, int max)
{
	int userInput;

	while (true)
	{
		cout << "Input: ";
		cin >> userInput;

		if (!cin.fail() && userInput >= min && userInput <= max)
		{
			return userInput;
		}
		else
		{
			cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
			cin.clear(); // Clear the error flag
			cin.ignore(1000, '\n'); // Discard invalid input
		}
	}
}
