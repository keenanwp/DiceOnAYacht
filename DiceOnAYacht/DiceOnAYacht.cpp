// DiceOnAYacht.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "GameManager.h"

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	GameManager gameManager;
	if (argc == 2 && (std::string(argv[1]) == "-t" || std::string(argv[1]) == "--test"))
		gameManager.RunTests();
	else if (argc == 1)
		gameManager.RunGame();
	else
	{
		std::cerr << "Usage: " << argv[0] << " <option(s)>\n"
			<< "Options:\n"
			<< "\t-t,--test \tRun in test mode"
			<< std::endl;

		return 1;
	}

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
