
#ifndef _CAGE_REF
#define _CAGE_REF

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "./Habitats/Cages.hpp"
#include "./Animals/Eagle.hpp"

std::vector<std::string> splitStringBy(std::string text, char splitter)
{
	std::vector<std::string> ret;
	int pos;
	while ((pos = text.find(splitter)) != std::string::npos)
	{
		ret.push_back(text.substr(0, pos));
		text = text.substr(pos + 1, text.size());
	}
	ret.push_back(text.substr(0, pos));
	return ret;
}

class Zoo
{
private:
	float budget = 0.0f;
	std::vector<Cages *> _cages;
	std::string _testFileName = "";

private:
	Sex determineSex(std::string text)
	{
		Sex animalSex = Sex::UNKNOWN;
		if (text == "male")
		{
			animalSex = Sex::MALE;
		}
		else if (text == "female")
		{
			animalSex = Sex::FEMALE;
		}
		else
		{
			std::cout << "Unrecognised Sex for animal" << std::endl;
		}
		return animalSex;
	}

private:
	Animal *buyEagle(std::string text)
	{
		bool male;
		Age age;
		const auto &tmp = splitStringBy(text, ' ');

		Sex sexe = determineSex(tmp[1]);
		if (sexe == Sex::UNKNOWN)
		{
			return nullptr;
		}
		age._years = std::atoi(tmp[2].c_str());
		std::cout << "Buying new Eagle<" << ((male) ? "male" : "female")
			  << "> with age :" << age._years << std::endl;
		return new Eagle(age, male);
	}

private:
	void buyAnimal(std::string text)
	{
		Animal *newAnimal = nullptr;
		text = text.substr(4, text.size());
		if (text.find("eagle") != std::string::npos)
		{
			newAnimal = buyEagle(text);
		}
		else if (text.find("tiger") != std::string::npos)
		{
		}

		if (newAnimal == nullptr)
		{
			std::cout << "Unrecognized animal, ignoring instruction." << std::endl;
		}
	}

	void sellAnimal(std::string text) {}
	void passDays(std::string text) {}
	void setBudget(std::string text)
	{
		budget = std::stof(text.substr(7, text.size() - 7));
		std::cout << "Zoo budget: " << budget << std::endl;
	}

private:
	void passADay()
	{
	}

public:
	Zoo(std::string testFileName) : _testFileName{testFileName} {}
	int startSimulation()
	{
		std::string text;
		std::ifstream file(_testFileName);
		getline(file, text);
		if (text.compare(0, 7, "budget:") == 0)
		{
			setBudget(text);
		}
		else
		{
			std::cout << "Unable to start simulation, budget not fixed" << std::endl;
			return EXIT_FAILURE;
		}

		while (getline(file, text))
		{
			if (text[0] == '#')
			{
				continue;
			}
			// Simulation want to buy something
			if (text.compare(0, 3, "buy") == 0)
			{
				buyAnimal(text);
			}

			// Simulation want to sell something
			if (text.compare(0, 4, "sell") == 0)
			{
				sellAnimal(text);
			}

			// Simulation want to pass X days
			if (text.compare(0, 3, "pass") == 0)
			{
				passDays(text);
			}
		}
		file.close();
		return EXIT_SUCCESS;
	}
};

#endif