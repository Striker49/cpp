#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0)
{

}

Point::Point(float const& x, float const& y) : _x(x), _y(y)
{

}

Point::Point(Point const& src)
{
	*this = src;
}

Point& Point::operator=(Point const& rhs)
{
	if (this != &rhs)
	{

	}
	return *this;
}

Point::~Point(void)
{
}

Fixed const& Point::getx( void ) const
{
	return(this->_x);
}

Fixed const& Point::gety( void ) const
{
	return(this->_y);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float Area = ((a.getx()(b.gety() - c.gety()) + b.getx()(c.gety() - a.gety()) + c.getx()(a.gety() - b.gety()))/ 2);

	// float Area1 = ((x(y2 - y3) + x(y3 - y1) + x(y1 - y2))/ 2);

	// float Area2 = ((x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))/ 2);

	// float Area3 = ((x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2))/ 2);


}
