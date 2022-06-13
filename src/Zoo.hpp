
#ifndef _ZOO_
#define _ZOO_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <functional>

#include "./Habitats/Cages.hpp"
#include "./Animals/Eagle.hpp"
#include "./Determine.hpp"
#include "./Accountability.hpp"

using Action = std::function<bool(std::vector<std::string> &)>;

class Zoo
{
private:
	std::vector<Cages *> _cages;
	Accountability _accountant;
	std::string _testFileName = "";

	static const std::vector<std::pair<InputType, Action>> inputToAction;

private: // Utils function
	void passADay();

private: // Generating animal
	static Animal *buyEagle(const std::vector<std::string> &, bool sexe);
	static Animal *buyChicken(const std::vector<std::string> &, bool sexe);
	static Animal *buyTiger(const std::vector<std::string> &, bool sexe);

private: // Input to Action function
	static bool buyAnimal(const std::vector<std::string> &parameters);
	static bool sellAnimal(const std::vector<std::string> &parameters);
	static bool passDays(const std::vector<std::string> &parameters);
	bool setBudget(std::string text);

private: // Simulation Events
public:	 // Public function to handle simulation
	Zoo(const char *testFileName) : _testFileName{std::string(testFileName)} {}
	int startSimulation();
};

#endif