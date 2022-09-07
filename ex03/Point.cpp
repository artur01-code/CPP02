#include "Point.hpp"

Point::Point() : x(0), y(0)
{

}

Point::Point(const float new_x, const float new_y) : x(new_x), y(new_y) 
{

}

Point::Point(const Point &copy) : x(copy.getX()), y(copy.getY()) 
{

};

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


