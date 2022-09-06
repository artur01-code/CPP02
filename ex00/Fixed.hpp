#include <iostream>

class Fixed {
	public:
	//default constructor
	Fixed();
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
};
