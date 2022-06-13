
#ifndef _CAGES
#define _CAGES

#include <vector>
#include "../Animals/Animal.hpp"
#include "../Animals/AnimalType.hpp"
#include "./CagesReferences.hpp"

// Forward declaration pour les erreur de compil
class CageReference;

class Cages
{
private:
	const CageReference &_cageRef;
	std::vector<Animal *> _animals; // All the stored animals in the cage
	AnimalType _animalType;		// Type of animals stored in this cage

public:
	Cages(const CageReference &cageRef, AnimalType cageType) : _cageRef{cageRef} {};
	void addAnimal(Animal *newAnimal)
	{
		_animals.push_back(newAnimal);
	}
};

#endif