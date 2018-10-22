#pragma once

#include <vector>

class Category;

enum CategoryName
{
	ONES = 0,
	TWOS,
	THREES,
	FOURS,
	FIVES,
	SIXES,
	SEVENS,
	EIGHTS,
	THREEOFAKIND,
	FOUROFAKIND,
	FULLHOUSE,
	SMALLSTRAIGHT,
	LARGESTRAIGHT,
	ALLDIFFERENT,
	CHANCE,
	ALLSAME,
	ALL
};

class CategoryManager
{
public:
	CategoryManager(int maxDiceValue);
	~CategoryManager();

	int GetCategoryScore(CategoryName categoryName, const std::vector<int>& diceRoll) const;

private:
	std::vector<Category*> _categories;
};

