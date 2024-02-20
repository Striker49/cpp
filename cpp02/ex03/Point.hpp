#pragma once
#include "Fixed.hpp"
#include "Point.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point(void);
	Point(Point const& src);
	Point(float const x, float const y);
	~Point(void);
	Point const& operator=(Point const& rhs);
	Fixed const& getx(void);
	Fixed const& gety(void);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
