#include "Fixed.hpp"

#ifndef POINT_HPP
# define POINT_HPP

class Point {
	public:
	//default constructor initializes with 0
	Point() : x(0), y(0) {}
	//constructor that takes two const and then initializes
	Point(const float new_x, const float new_y) : x(new_x), y(new_y) {}
	//copy constructor
	Point(const Point &copy) : x(copy.getX()), y(copy.getY()) {};
	//copy assignment operator overload
	Point& operator=(const Point &copy);
	//destructor
	~Point();

	//attributes
	private:
	const Fixed x;
	const Fixed y;

	public:
	Fixed getX() const;
	Fixed getY() const;
};

std::ostream	&operator<<(std::ostream &os, const Point &point);

#endif