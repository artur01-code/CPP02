#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( const Point &a, const Point &b, const Point& c, const Point& point);

int main()
{
	{
		std::cout << "******************Test 1: inside********************" << std::endl;
		Point a(1, 0);
		std::cout << "a" << a;
		Point b(5, 0);
		std::cout << "b" << b;
		Point c(5, 5);
		std::cout << "c" << c;
		Point d(2, 1);
		std::cout << "d" << d;

		if(bsp(a, b, c, d) == true)
			std::cout << "Point is in the triangle" << std::endl;
		else
			std::cout << "Point is not in the triangle" << std::endl;
	}
	{
		std::cout << "******************Test 2: outside********************" << std::endl;
		Point a(1, 0);
		std::cout << "a" << a;
		Point b(5, 0);
		std::cout << "b" << b;
		Point c(5, 5);
		std::cout << "c" << c;
		Point d(9, 7);
		std::cout << "d" << d;

		if(bsp(a, b, c, d) == true)
			std::cout << "Point is in the triangle" << std::endl;
		else
			std::cout << "Point is not in the triangle" << std::endl;
	}
}