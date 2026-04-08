#include "Fixed.hpp"

const int Fixed::_nbFracBits = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->_nbValue = 0;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbValue);
}

void Fixed::setRawBits(const int raw)
{
	this->_nbValue = raw;
}
