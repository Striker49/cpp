#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0)
{
	// std::cout << "Constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
	// std::cout << "Float constructor called" << std::endl;
}

Point::Point(Point const& src) : _x(src._x), _y(src._y)
{
    // std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Point& Point::operator=(Point const& rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Fixed(this->_x) = rhs._x;
		Fixed(this->_y) = rhs._y;
	}
	return (*this);
}

Point::~Point(void)
{
	// std::cout << "Desstructor called" << std::endl;
}

Fixed const& Point::getx( void ) const
{
	return(this->_x);
}

Fixed const& Point::gety( void ) const
{
	return(this->_y);
}
