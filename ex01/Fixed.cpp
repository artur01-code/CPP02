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

//belongs to ex01
std::ostream	&operator<<(std::ostream &os, const Fixed &point)
{
	os << "fixed: " << point.toFloat();
	return (os);
}