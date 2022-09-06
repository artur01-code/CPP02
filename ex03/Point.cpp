#include "Point.hpp"

Point& Point::operator=(const Point &copy)
{
	Point *out;

	out = new Point(copy);
	return (*out);
}

Point::~Point()
{

}

Fixed Point::getX() const
{
	return (x);
}

Fixed Point::getY() const
{
	return (y);
}

std::ostream	&operator<<(std::ostream &os, const Point &point)
{
	os << "(" << point.getX() << "/" << point.getY() << ")" << std::endl;
	return (os);
}

//bool bsp( Point const a, Point const b, Point const c, Point const point)


