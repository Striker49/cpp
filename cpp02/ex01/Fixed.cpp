#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->_integer = 0;
}

Fixed::Fixed(Fixed const& src)
{
    std::cout << "Copy constructor called" << std::endl;

    *this = src;
}

Fixed::Fixed(int const& src)
{
    std::cout << "Int constructor called" << std::endl;

    this->_integer = src << _fract;
}

Fixed::Fixed(float const& src)
{
    std::cout << "Float constructor called" << std::endl;

    this->_integer = roundf(src * (1 << _fract));
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &rhs)
    {
        this->_integer = rhs._integer;
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

    return (this->_integer);
}

void Fixed::setRawBits( int const raw)
{
    std::cout << "setRawBits function called" << std::endl;

    this->_integer = raw;
}

int Fixed::toInt( void ) const
{
    return (static_cast<int>(this->_integer) >> _fract);
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->_integer) / (1 << _fract));
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return(o);
}
