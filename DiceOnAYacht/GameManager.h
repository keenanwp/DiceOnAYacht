#pragma once

#include "CategoryManager.h"

#include <vector>

class GameManager
{
public:
	GameManager();

	void RunGame();
	void RunTests();

	int GetNumberOfDice() const { return _numDice; }
	int GetMaxDiceValue() const { return _maxDiceVal; }

private:
	CategoryManager _categoryManager;
	std::vector<int> _diceRoll;

	static const int _numDice = 5;
	static const int _maxDiceVal = 8;
};

