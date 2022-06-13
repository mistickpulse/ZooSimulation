

#ifndef _FOOD_PRICE
#define _FOOD_PRICE

#include <vector>
#include <utility>
#include <string>
#include "FoodType.hpp"

class FoodPrice
{
	static const std::vector<std::pair<FoodType, float>> foodPrice;
};
#endif