
#ifndef _CAGE_REF
#define _CAGE_REF

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "./Habitats/Cages.hpp"
#include "./Animals/Eagle.hpp"
#include "./Determine.hpp"

using Action = std::function<bool(std::vector<std::string> &)>;

class Zoo
{
private:
	float budget = 0.0f;
	std::vector<Cages *> _cages;
	std::string _testFileName = "";

	static const std::vector<std::pair<InputType, Action>> inputToAction;

private:
	Animal *
	buyEagle(std::string text);

private:
	static bool buyAnimal(const std::vector<std::string> &parameters);
	static bool sellAnimal(const std::vector<std::string> &parameters);
	static bool passDays(const std::vector<std::string> &parameters);
	bool setBudget(std::string text);

private:
	void passADay();

public:
	Zoo(const char *testFileName) : _testFileName{std::string(testFileName)} {}
	int startSimulation();
};

#endif