#include <iostream>

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
};

std::ostream	&operator<<(std::ostream &os, const Fixed &point);
