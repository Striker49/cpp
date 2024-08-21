#include "Whatever.tpp"


int main()
{
	int x = 5;
	int y = 4;
	int z = 5;

	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "The min is: " << min(x, y) << std::endl;
	std::cout << "The max is: " << max(x, y) << std::endl;
	std::cout << std::endl;

	std::cout << "Swapping x and y values" << std::endl;
	swap(x, y);
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "The min is: " << min(x, y) << std::endl;
	std::cout << "The max is: " << max(x, y) << std::endl;
	std::cout << std::endl;


	std::cout << "----Both of equal value----" << std::endl << std::endl;

	std::cout << "y: " << y << std::endl;
	std::cout << "z: " << z << std::endl;
	std::cout << "The min is: " << min(y, z) << std::endl;
	std::cout << "The max is: " << max(y, z) << std::endl;
	std::cout << std::endl;


	std::cout << "----Float----" << std::endl << std::endl;

	float f = 4.2f;
	float f2 = 42.0f;
	std::cout << "f: " << f << std::endl;
	std::cout << "f2: " << f2 << std::endl;
	std::cout << "The min is: " << min(f, f2) << std::endl;
	std::cout << "The max is: " << max(f, f2) << std::endl;
	std::cout << "Swapping f and f2 values" << std::endl;
	swap(f, f2);
	std::cout << "f: " << f << std::endl;
	std::cout << "f2: " << f2 << std::endl;
	std::cout << "The min is: " << min(f, f2) << std::endl;
	std::cout << std::endl;

}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;
// 	swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }
