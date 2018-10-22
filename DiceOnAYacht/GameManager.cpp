#include "GameManager.h"

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>


GameManager::GameManager()
	: _diceRoll(_numDice), _categoryManager(_maxDiceVal)
{
}

void GameManager::RunGame()
{
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "Welcome to Dice On a Yacht!\n\n";
	while (true)
	{
		std::cout << "Enter a Scoring Category number:\n";
		std::cout << "1 - ONES\n"
			<< "2 - TWOS\n"
			<< "3 - THREES\n"
			<< "4 - FOURS\n"
			<< "5 - FIVES\n"
			<< "6 - SIXES\n"
			<< "7 - SEVENS\n"
			<< "8 - EIGHTS\n"
			<< "9 - THREEOFAKIND\n"
			<< "10 - FOUROFAKIND\n"
			<< "11 - FULLHOUSE\n"
			<< "12 - SMALLSTRAIGHT\n"
			<< "13 - LARGESTRAIGHT\n"
			<< "14 - ALLDIFFERENT\n"
			<< "15 - CHANCE\n"
			<< "16 - ALLSAME\n"
			<< "17 - ALL\n"
			<< "0 - Quit Game\n";

		int category;
		if (!(std::cin >> category))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Invalid category input!  Input must be an integer!\n";
		}
		else
		{
			if (category == 0)
				break;

			if (category < 0 || category > CategoryName::ALL + 1)
				std::cerr << "Invalid category entered!\n";
			else
			{
				std::cout << "Roll = [";
				for (size_t i = 0; i < _diceRoll.size(); ++i)
					std::cout << " " << (_diceRoll[i] = (rand() % 7) + 1) << " ";

				std::cout << "]\n";

				std::cout << "Score = "
					<< _categoryManager.GetCategoryScore(static_cast<CategoryName>(category - 1), _diceRoll)
					<< std::endl;
			}
		}

		system("pause");
	}
}

void GameManager::RunTests()
{
	std::ifstream testFile;
	testFile.open("../DiceOnAYacht/Data/testcases.txt", std::ios::in);
	if (!testFile.is_open())
	{
		std::cerr << "Failed to open test file!\n";
		return;
	}

	bool failure = false;

	while (testFile.good())
	{
		int category;
		if (!(testFile >> category))
		{
			if (!testFile.eof())
				std::cerr << "Invalid category input!\n";

			break;
		}

		if (category < 1 || category > CategoryName::ALL + 1)
		{
			std::cerr << "Invalid category entered!\n"
				<< "Category = " << category << std::endl;

			break;
		}

		bool failReadDiceRoll = false;
		for (size_t i = 0; i < _diceRoll.size(); ++i)
		{
			if (!(testFile >> _diceRoll[i]))
			{
				std::cerr << "Invalid dice roll input!\n";
				failReadDiceRoll = true;
				break;
			}
			
			if (_diceRoll[i] < 1 || _diceRoll[i] > _maxDiceVal)
			{
				std::cerr << "Invalid dice value entered!\n"
					<< "Dice Value = " << _diceRoll[i] << std::endl;
				failReadDiceRoll = true;
				break;
			}
		}

		if (failReadDiceRoll)
			break;

		int expectedResult;
		if (!(testFile >> expectedResult))
		{
			std::cerr << "Invalid expected result input!\n";
			break;
		}

		int actualResult = _categoryManager.GetCategoryScore(static_cast<CategoryName>(category - 1), _diceRoll);
		if (expectedResult != actualResult)
		{
			failure = true;

			std::cout << "TEST FAILED: \n"
				<< "Input: Category = " << category << "; Roll = [";

			for (size_t i = 0; i < _diceRoll.size(); ++i)
				std::cout << " " << _diceRoll[i] << " ";

			std::cout << "]\n";

			std::cout << "Expected: " << expectedResult << std::endl
				<< "Actual: " << actualResult << std::endl;
		}
	}

	if (!testFile.eof())
		std::cerr << "Error Reading test input!\n";
	else if (!failure)
		std::cout << "TESTS PASSED!\n";

	testFile.close();
}
