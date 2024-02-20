#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point a(0, 0);
	Point b(6, 0);
	Point c(6, 6);
	Point point(3, 1);
	if (bsp(a, b, c , point))
		std::cout << "Point is in the triangle" << std::endl;
	else
		std::cout << "Point is not in the triangle..." << std::endl;
	return (0);

}
