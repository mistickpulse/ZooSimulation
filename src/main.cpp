
#include <stdlib.h>
#include "./Zoo.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 1)
		{
			std::cout << "[Error] You must provide a test file" << std::endl;
		}
		else if (ac > 2)
		{
			std::cout << "[Error] Invalid parameters, must only provide one file" << std::endl;
		}
		std::cout << "Usage: ./zooSimulator <PathToTestFile>" << std::endl;
		return EXIT_SUCCESS;
	}
	Zoo myzoo(av[1]);
	return myzoo.startSimulation();
}