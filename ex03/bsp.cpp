#include "Fixed.hpp"
#include "Point.hpp"

//https://totologic.blogspot.com/2014/01/accurate-point-in-triangle-test.html

bool bsp( const Point &a, const Point &b, const Point& c, const Point& point)
{
	Fixed demon = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX() - b.getX()) * (a.getY() - c.getY());
	Fixed scalar1 = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX() - b.getX()) * (point.getY() - c.getY())) / demon;
	Fixed scalar2 = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX() - c.getX()) * (point.getY() - c.getY())) / demon;
	Fixed scalar3 = Fixed(1) - scalar1 - scalar2;
	return ((scalar1 <= 1 && scalar1 >= 0) && (scalar2 <= 1 && scalar2 >= 0) && (scalar3 <= 1 && scalar3 >= 0));
}
