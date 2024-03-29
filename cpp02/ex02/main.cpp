#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
	int resultat;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;


	resultat = c > b ;
	std::cout << resultat << std::endl;
	resultat = b >= b ;
	std::cout << resultat << std::endl;
	resultat = c < b ;
	std::cout << resultat << std::endl;
	resultat = c <= c ;
	std::cout << resultat << std::endl;
	resultat = c == b ;
	std::cout << resultat << std::endl;
	resultat = c != b ;
	std::cout << resultat << std::endl;

	std::cout << std::endl;
	std::cout << c << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( c, b ) << std::endl;
}
