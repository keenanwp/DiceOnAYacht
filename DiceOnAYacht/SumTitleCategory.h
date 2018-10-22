#pragma once

#include "Category.h"

class SumTitleCategory :
	public Category
{
public:
	SumTitleCategory(int titleNum);

	virtual int Score(const std::vector<int>& diceRoll);

private:
	int _titleNum;
};

