#pragma once

#include "Category.h"

class AllSameCategory :
	public Category
{
public:
	virtual int Score(const std::vector<int>& diceRoll);
};

