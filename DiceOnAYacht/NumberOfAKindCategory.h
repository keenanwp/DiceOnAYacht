#pragma once

#include "Category.h"

class NumberOfAKindCategory :
	public Category
{
public:
	NumberOfAKindCategory(int numberOfAKind, int maxDiceValue);
	virtual int Score(const std::vector<int>& diceRoll);

private:
	int _numberOfAKind;
	int _maxDiceValue;
};

