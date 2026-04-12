#include "Fixed.hpp"

const int Fixed::_nbFracBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_nbValue = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(value << this->_nbFracBits);
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(value * (1 << this->_nbFracBits)));
}

Fixed::Fixed(const Fixed& input)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = input;
}

Fixed& Fixed::operator=(const Fixed& input)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &input)
		this->_nbValue = input.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

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
