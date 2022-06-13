
#include "./AnimalType.hpp"
#include "./Age.hpp"

#ifndef _ANIMAL
#define _ANIMAL

class Animal
{
protected:
	Age _age;
	AnimalType _type; // Type d'animal
	float _foodPerDay;
	int _dayBeforeFeed;
	int _yearsOfLife;
	bool _male;
	// bool _isSick = false; // Par defaut l'animal n'est pas malade

public:
	Animal(Age age, AnimalType type, bool male, float foodpd, int dayBfFeed, int yOfLife)
	{
		_age = age;
		_type = type;
		_male = male;
		_foodPerDay = foodpd;
		_dayBeforeFeed = dayBfFeed;
		_yearsOfLife = yOfLife;
	}

public:
	virtual float getBuyPrice() const = 0;	// Recuperer dans la classe enfant le prix d'achat
	virtual float getSellPrice() const = 0; // Recuperer dans la classe enfant le prix de vente
};

#endif