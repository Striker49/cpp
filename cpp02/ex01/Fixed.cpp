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

Fixed::Fixed(int const& src)
{
    std::cout << "Int constructor called" << std::endl;

    // *this = src;
    this->integer = src;
    this->integer = toInt();
}

Fixed::Fixed(float const& src)
{
    std::cout << "Float constructor called" << std::endl;

    // *this = src;
    this->integer = src;
    this->integer = toFloat();
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

int Fixed::toInt( void ) const
{
    return (static_cast<int>(this->integer));
}

float Fixed::toFloat( void ) const
{
    return (static_cast<float>(this->integer));
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
    o << rhs.getRawBits();
    return(o);
}
