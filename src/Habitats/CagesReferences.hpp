
#ifndef _CAGE_REF
#define _CAGE_REF

#include <vector>
#include <utility>
#include <string>
#include "FoodType.hpp"
#include "../Animals/AnimalType.hpp"

class CageReference // On peux faire une struct ici a la place mais flemme lmao
{
public:
	AnimalType Cagetype;
	int size;
	float priceBuy;
	float priceSell;
};

class CagesReferenceList
{
};

#endif