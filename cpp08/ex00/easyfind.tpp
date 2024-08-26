#pragma once
#include "easyfind.hpp"
#include <limits>
#include <iostream>
#include <algorithm>

template <typename T>
void easyfind( T const x, int const integer)
{
	typename T::const_iterator it = std::find(x.begin(), x.end(), integer);
	if (it != x.end())
		std::cout << "\'" << *it << "\'" << " was found at location [" << distance(x.begin(), it) << "]"<< std::endl;
	else
		std::cout << "\'" << integer << "\' was not found..!" << std::endl;
}

template <typename T>
void print( T const x)
{
	for (typename T::const_iterator it = x.begin(); it != x.end(); it++)
	{
		std::cout << *it << std::endl; 
	}
	std::cout << std::endl;
}
