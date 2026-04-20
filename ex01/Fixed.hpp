#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedValue;
	static const int bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &other);
	Fixed::Fixed(const int &val);
	Fixed::Fixed(const float &val);
	Fixed &operator=(const Fixed &other);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void);
	int toInt();
};

#endif
