#pragma once

#include "Category.h"

class AllDifferentCategory :
	public Category
{
public:
	AllDifferentCategory(int maxDiceValue);
	virtual int Score(const std::vector<int>& diceRoll);

private:
	int _maxDiceValue;
};

