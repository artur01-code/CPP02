#include "Fixed.hpp"

Fixed::Fixed()
{
	val_ = 0;
	std::cout << "Default Constructor called" << std::endl;
};

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