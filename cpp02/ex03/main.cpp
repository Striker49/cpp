#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point a(0, 0);
	Point b(6, 0);
	Point c(6, 6);
	Point point(3, 1);
	Point point2(-3, 1);
	Point point3(7, 7);
	Point point4(6, 0);
	Point point5(5.9f, 0.1f);

	if (bsp(a, b, c , point))
		std::cout << "\033[1;32mPoint is in the triangle\033[0;37m" << std::endl;
	else
		std::cout << "\033[1;31mPoint is in the triangle\033[0;37m" << std::endl;
	if (bsp(a, b, c , point2))
		std::cout << "\033[1;32mPoint is in the triangle\033[0;37m" << std::endl;
	else
		std::cout << "\033[1;31mPoint is in the triangle\033[0;37m" << std::endl;
	if (bsp(a, b, c , point3))
		std::cout << "\033[1;32mPoint is in the triangle\033[0;37m" << std::endl;
	else
		std::cout << "\033[1;31mPoint is in the triangle\033[0;37m" << std::endl;
	if (bsp(a, b, c , point4))
		std::cout << "\033[1;32mPoint is in the triangle\033[0;37m" << std::endl;
	else
		std::cout << "\033[1;31mPoint is in the triangle\033[0;37m" << std::endl;
	if (bsp(a, b, c , point5))
		std::cout << "\033[1;32mPoint is in the triangle\033[0;37m" << std::endl;
	else
		std::cout << "\033[1;31mPoint is in the triangle\033[0;37m" << std::endl;
	return (0);
}
