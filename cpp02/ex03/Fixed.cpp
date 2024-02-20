#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void)
{
    // std::cout << "Default constructor called" << std::endl;
    this->_integer = 0;
}

Fixed::Fixed(Fixed const& src)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(int const& src)
{
    // std::cout << "Int constructor called" << std::endl;

    this->_integer = src << _fract;
}

Fixed::Fixed(float const& src)
{
    // std::cout << "Float constructor called" << std::endl;

    // std::cout << "float value = " << this->_integer << std::endl;
    this->_integer = roundf(src * (1 << _fract));
}

Fixed& Fixed::operator=(Fixed const& rhs)
{
    // std::cout << "Overload operator "=" called" << std::endl;

    if (this != &rhs)
    {
        this->_integer = rhs._integer;
    }
    return (*this);
}

bool Fixed::operator<(Fixed const& rhs)
{
    // std::cout << "Overload operator "<" called" << std::endl;

    return (this->_integer < rhs._integer);
}

bool Fixed::operator==(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;

    return (this->_integer == rhs._integer);
}

bool Fixed::operator<=(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;

    return (this->_integer <= rhs._integer);
}

bool Fixed::operator>(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;

    return (this->_integer > rhs._integer);
}

bool Fixed::operator>=(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;

    return (this->_integer >= rhs._integer);
}

Fixed Fixed::operator*(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;
    Fixed product;
    product._integer = roundf((this->toFloat() * rhs.toFloat()) * (1 << this->_fract));

    return (product);
}

Fixed Fixed::operator/(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;
    Fixed quotient;
    quotient._integer = roundf((this->toFloat() / rhs.toFloat()) * (1 << this->_fract));

    return (quotient);
}

Fixed Fixed::operator+(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;
    Fixed res;
    res._integer = this->_integer + rhs._integer;
    return (res);
}

Fixed Fixed::operator-(Fixed const& rhs)
{
    // std::cout << "Overload operator operator called" << std::endl;
    Fixed res;
    res._integer = this->_integer - rhs._integer;
    return (res);
}

Fixed Fixed::operator++( int )
{
    // std::cout << "Overload operator operator called" << std::endl;
    Fixed temp = *this;

    ++this->_integer;
    return (temp);
}

Fixed Fixed::operator--( int )
{
    // std::cout << "Overload operator operator called" << std::endl;
    Fixed temp;

    --this->_integer;
    return (temp);
}

Fixed& Fixed::operator++()
{
    // std::cout << "Overload operator operator called" << std::endl;

    this->_integer++;
    return (*this);
}

Fixed& Fixed::operator--()
{
    // std::cout << "Overload operator operator called" << std::endl;

    this->_integer--;
    return (*this);
}


Fixed::~Fixed(void)
{
    // std::cout << "Destructor called" << std::endl;

}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits function called" << std::endl;

    return (this->_integer);
}

void Fixed::setRawBits( int const raw)
{
    // std::cout << "setRawBits function called" << std::endl;

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

const Fixed& Fixed::min(Fixed const& rhs, Fixed const& rhs2)
{
    if (rhs.getRawBits() < rhs2.getRawBits())
        return (rhs);
    else
        return (rhs2);
}

Fixed& Fixed::min(Fixed& rhs, Fixed& rhs3)
{
    if (rhs.getRawBits() < rhs3.getRawBits())
        return (rhs);
    else
        return (rhs3);
}

const Fixed& Fixed::max(Fixed const& rhs, Fixed const& rhs2)
{
    if (rhs.getRawBits() < rhs2.getRawBits())
        return (rhs2);
    else
        return (rhs);
}

Fixed& Fixed::max(Fixed& rhs, Fixed& rhs3)
{
    if (rhs.getRawBits() < rhs3.getRawBits())
        return (rhs3);
    else
        return (rhs);
}
