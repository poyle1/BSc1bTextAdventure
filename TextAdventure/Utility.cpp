#include "Utility.h"
#include <iostream>

namespace MilkAndSugar::UI
{
    int getValidIntInput(int min, int max)
    {
        int userInput;
        while (true)
        {
            std::cout << "Input: ";
            std::cin >> userInput;
            if (!std::cin.fail() && userInput >= min && userInput <= max)
            {
                return userInput;
            }
            else
            {
                std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(1000, '\n'); // Discard invalid input
            }
        }
    }

    // Pauses the program and waits for user input before continuing
    void pauseAndFlush()
    {
        std::cout << std::endl;
        system("pause");
    }

    // Pauses the program, then clears the screen output
    void pauseAndWipe()
    {
        std::cout << std::endl;
        system("pause");
        system("cls");
    }
}