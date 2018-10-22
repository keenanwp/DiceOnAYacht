#pragma once

#include "Category.h"

class FullHouseCategory :
	public Category
{
public:
	FullHouseCategory(int maxDiceValue);
	virtual int Score(const std::vector<int>& diceRoll);

private:
	int _maxDiceValue;
};

