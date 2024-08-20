#include "Array.hpp"

int main()
{
	int *a = new int();
	std::cout << "a: " << *a << std::endl;

	Array<int> b(2);
	// b[0] = 1;
	// b[1] = 2;
	std::cout << "b: " << &b << std::endl;
	// std::cout << "b[0]: " << b[0] << std::endl;
	// std::cout << "b[1]: " << b[1] << std::endl;
	// try{
		// std::cout << "b[2]: " << b[-1] << std::endl;
	// }
	// catch(std::exception &e){std::cout << "Index out of bounds..!" << std::endl;}

	delete a;
}