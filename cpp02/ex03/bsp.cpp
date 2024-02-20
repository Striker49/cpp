#include "Fixed.hpp"
#include "Point.hpp"

Fixed& calc_area(Point a, Point b, Point c, Fixed& area)
{
	Fixed& total = area;
	total = Fixed((a.getx().toFloat() * (b.gety().toFloat() - c.gety().toFloat())
		+ (b.getx().toFloat() * (c.gety().toFloat() - a.gety().toFloat()))
	 	+ c.getx().toFloat() * (a.gety().toFloat() - b.gety().toFloat())))/ 2;

	 if (total < 0)
	 	total = total * -1;
	return (total);
	
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = calc_area(a, b, c, area);

	Fixed area1 = calc_area(point, b, c, area1);

	Fixed area2 = calc_area(point, c, a, area2);

	Fixed area3 = calc_area(point, a, b, area3);

	if (area == 0 || area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	if (area == area1 + area2 + area3)
		return (true);
	return (false);
}
