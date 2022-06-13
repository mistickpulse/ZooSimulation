
#include <stdlib.h>
#include "./Zoo.hpp"

int main()
{
	Zoo myzoo("../Tests/test1.txt");
	myzoo.startSimulation();
	return EXIT_SUCCESS;
}