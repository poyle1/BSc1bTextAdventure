#include "Utility.h"
#include <iostream>

using namespace std;

namespace Utility {
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

    // Pauses the program and waits for user input before continuing
    void pauseAndFlush()
    {
        cout << endl;
        system("pause");
    }

    // Pauses the program, then clears the screen output
    void pauseAndWipe()
    {
        cout << endl;
        system("pause");
        system("cls");
    }
}