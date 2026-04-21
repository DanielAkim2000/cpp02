#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->fixedValue = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int &val)
{
	this->fixedValue = val << this->bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &val)
{
	this->fixedValue = roundf(val * (1 << this->bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (&other != this)
	{
		this->fixedValue = other.fixedValue;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedValue);
}

void Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedValue = raw;
}

int Fixed::toInt(void) const
{
	return (this->fixedValue >> this->bits);
}

float Fixed::toFloat(void) const
{
	float r;

	r = static_cast<float>(this->fixedValue) / (1 << this->bits);
	return (r);
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}
