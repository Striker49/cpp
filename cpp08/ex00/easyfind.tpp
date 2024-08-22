#include <limits>
#include <iostream>

template <typename T>
void easyfind( T const x, int const integer)
{
	for (unsigned long i = 0; i < x.size(); i++)
	{
		if (x[i] == integer)
		{
			std::cout << "\'" << integer << "\'" << " was found at location " << "[" << i << "]!" << std::endl;
			return;
		}
	}
	std::cout << integer << " was not found..!" << std::endl;
}
