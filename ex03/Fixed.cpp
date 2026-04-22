#include "Fixed.hpp"

Fixed::Fixed(void) : fixedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixedValue(other.fixedValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int &val) : fixedValue(val << bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &val) : fixedValue(roundf(val * (1 << bits)))
{
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

bool Fixed::operator>(const Fixed &other) const
{
	if (this->fixedValue > other.fixedValue)
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &other) const
{
	if (this->fixedValue < other.fixedValue)
		return (true);
	return (false);
}

bool Fixed::operator>=(const Fixed &other) const
{
	if (this->fixedValue >= other.fixedValue)
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &other) const
{
	if (this->fixedValue <= other.fixedValue)
		return (true);
	return (false);
}

bool Fixed::operator==(const Fixed &other) const
{
	if (this->fixedValue == other.fixedValue)
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &other) const
{
	if (this->fixedValue != other.fixedValue)
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result(*this);
	result.fixedValue += other.fixedValue;
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result(*this);
	result.fixedValue -= other.fixedValue;
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	long raw;

	raw = static_cast<long>(this->fixedValue) * static_cast<long>(other.fixedValue);
	result.fixedValue = static_cast<int>(raw >> this->bits);
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.fixedValue == 0)
		return (*this);
	Fixed result;
	long raw;

	raw = (static_cast<long>(this->fixedValue) << this->bits) / other.fixedValue;
	result.fixedValue = static_cast<int>(raw);
	return (result);
}

Fixed &Fixed::operator++(void)
{
	this->fixedValue++;
	return (*this);
}
Fixed &Fixed::operator--(void)
{
	this->fixedValue--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed last(*this);
	this->fixedValue++;
	return (last);
}

Fixed Fixed::operator--(int)
{
	Fixed last(*this);
	this->fixedValue--;
	return (last);
}

std::ostream &
operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return (out);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
