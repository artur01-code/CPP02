#include "Fixed.hpp"

Fixed::Fixed()
{
	val_ = 0;
	std::cout << "Default Constructor called" << std::endl;
};

//take new value and shift it bits times to the left because of nachkommastellen
Fixed::Fixed(const int &new_val)
{
	//(24bits).(8bits)
	std::cout << "Int Constructor called" << std::endl;
	val_ = new_val << bits_;
};

Fixed::Fixed(const float &new_val)
{
	std::cout << "Float Constructor called" << std::endl;
	this->val_ = roundf(new_val * (1 << bits_));
};

//die Function von oben umstellen, sodass sie Operation rueckwearts gemacht wird
float Fixed::toFloat(void) const
{
	return ((float)this->val_ / (float)(1 << this->bits_));
};

//die Function von oben umstellen, sodass sie Operation rueckwearts gemacht wird
int Fixed::toInt(void) const
{
	return (this->val_ >> this->bits_);
}

Fixed::Fixed(const Fixed &copy)
{
	this->val_ = copy.val_;
	std::cout << "Copy Constructor called" << std::endl;
};

Fixed& Fixed::operator=(const Fixed &copy)
{
	this->val_ = copy.val_;
	std::cout << "Copy Assignment Constructor called" << std::endl;
	return (*this);
};

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called " << std::endl;
	return (val_);
};

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called " << std::endl;
	this->val_ = raw;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &point)
{
	os << point.toFloat();
	return (os);
}

//ex02
//comparison operator

bool Fixed::operator>(const Fixed &obj)
{
	if (getRawBits() > obj.getRawBits())
		return (true);
	else
		return (false);
};

bool Fixed::operator<(const Fixed &obj)
{
	if (getRawBits() < obj.getRawBits())
		return (true);
	else
		return (false);
};

bool Fixed::operator>=(const Fixed &obj)
{
	if (getRawBits() >= obj.getRawBits())
		return (true);
	else
		return (false);
};

bool Fixed::operator<=(const Fixed &obj)
{
	if (getRawBits() <= obj.getRawBits())
		return (true);
	else
		return (false);
};

bool Fixed::operator==(const Fixed &obj)
{
	if (getRawBits() == obj.getRawBits())
		return (true);
	else
		return (false);
};

bool Fixed::operator!=(const Fixed &obj)
{
	if (getRawBits() != obj.getRawBits())
		return (true);
	else
		return (false);
};

//arithmetic operator
/*
the result of the calculation is a float
so we create a new object of the class Fixed and 
call the float constructor
*/
Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed a(toFloat() + obj.toFloat());
	return (a);
};

Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed a(toFloat() - obj.toFloat());
	return (a);
};

Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed a(toFloat() * obj.toFloat());
	return (a);
};

Fixed Fixed::operator/(const Fixed &obj)
{
	Fixed a(toFloat() / obj.toFloat());
	return (a);
};

//increment and decrement
//preincrement
Fixed& Fixed::operator++(void)
{
	setRawBits(getRawBits() + 1);
	return (*this);
};

Fixed& Fixed::operator--(void)
{
	setRawBits(getRawBits() - 1);
	return (*this);
};

//postincrement
Fixed Fixed::operator++(int)
{
	Fixed clone;
	int temp;

	clone = *this;
	temp = getRawBits();
	setRawBits(getRawBits() + 1);
	return (clone);
};

Fixed Fixed::operator--(int)
{
	Fixed clone;
	int temp;

	clone = *this;
	temp = getRawBits();
	setRawBits(getRawBits() - 1);
	return (clone);
};

//public overload functions

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
};

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
};

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
};

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
};
