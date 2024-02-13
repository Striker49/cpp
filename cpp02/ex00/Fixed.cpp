#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->integer = 0;
}

Fixed::Fixed(Fixed const& src)
{
    std::cout << "Copy constructor called" << std::endl;

    *this = src;
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs)
    {
        this->integer = rhs.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;

}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits function called" << std::endl;

    return (this->integer);
}

void Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits function called" << std::endl;

    this->integer = raw;
}