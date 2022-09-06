#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
	//default constructor
	Fixed();
	//default constructor with constant integer for fixed-point
	Fixed(const int &new_val);
	//default constructor with constant floating point numbers
	Fixed(const float &new_val);
	//copy constructor
	Fixed(const Fixed &copy);
	//copy assignment constructor
	Fixed& operator=(const Fixed &copy);
	//destructor
	~Fixed();

	//comparion operator
	//>      obj > obj; which one is bigger?
	bool operator>(const Fixed &obj); //the biggest raw big value is that shit
	bool operator<(const Fixed &obj);
	bool operator>=(const Fixed &obj);
	bool operator<=(const Fixed &obj);
	bool operator==(const Fixed &obj);
	bool operator!=(const Fixed &obj);

	//arithmetic operator
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);

	//increment and decrement
	//preincrement
	Fixed &operator++(void);
	Fixed &operator--(void);
	//postincrement
	Fixed operator++(int);
	Fixed operator--(int);

	//attributes
	private:
	int val_;
	static const int bits_ = 8;

	//methods
	public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	//public overload functions
	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif