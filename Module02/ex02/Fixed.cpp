#include "Fixed.hpp"

const int Fixed::_nbFracBits = 8;

Fixed::Fixed()
{
	this->_nbValue = 0;
}

Fixed::Fixed(const int value)
{
	this->setRawBits(value << this->_nbFracBits);
}

Fixed::Fixed(const float value)
{
	this->setRawBits(roundf(value * (1 << this->_nbFracBits)));
}

Fixed::Fixed(const Fixed& input)
{
	*this = input;
}

Fixed& Fixed::operator=(const Fixed& input)
{
	if (this != &input)
		this->_nbValue = input.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed& comp) const
{
	return (this->getRawBits() > comp.getRawBits());
}

bool Fixed::operator<(const Fixed& comp) const
{
	return (this->getRawBits() < comp.getRawBits());
}

bool Fixed::operator>=(const Fixed& comp) const
{
	return (this->getRawBits() >= comp.getRawBits());
}

bool Fixed::operator<=(const Fixed& comp) const
{
	return (this->getRawBits() <= comp.getRawBits());
}

bool Fixed::operator==(const Fixed& comp) const
{
	return (this->getRawBits() == comp.getRawBits());
}

bool Fixed::operator!=(const Fixed& comp) const
{
	return (this->getRawBits() != comp.getRawBits());
}

Fixed Fixed::operator+(const Fixed& add) const
{
	return Fixed(this->toFloat() + add.toFloat());
}

Fixed Fixed::operator-(const Fixed& sub) const
{
	return Fixed(this->toFloat() - sub.toFloat());
}

Fixed Fixed::operator*(const Fixed& mul) const
{
	return Fixed(this->toFloat() * mul.toFloat());
}

Fixed Fixed::operator/(const Fixed& div) const
{
	return Fixed(this->toFloat() / div.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->_nbValue++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	cpy(*this);
	this->_nbValue++;
	return (cpy);
}

Fixed &Fixed::operator--(void)
{
	this->_nbValue--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	cpy(*this);
	this->_nbValue--;
	return (cpy);
}

Fixed &Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed::~Fixed()
{}

int Fixed::getRawBits(void) const
{
	return (this->_nbValue);
}

void Fixed::setRawBits(const int raw)
{
	this->_nbValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_nbValue / (1 << this->_nbFracBits));
}

int Fixed::toInt(void) const
{
	return (this->_nbValue >> this->_nbFracBits);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &value)
{
	stream << value.toFloat();
	return (stream);
}
