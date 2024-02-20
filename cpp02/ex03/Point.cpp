#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0)
{

}

Point::Point(float const x, float const y) : _x(x), _y(y)
{

}

Point::Point(Point const& src) : _x(src._x), _y(src._y)
{
	*this = src;
}

Point const& Point::operator=(Point const& rhs)
{
	return (rhs);
}

Point::~Point(void)
{
}

Fixed const& Point::getx( void )
{
	return(this->_x);
}

Fixed const& Point::gety( void )
{
	return(this->_y);
}
