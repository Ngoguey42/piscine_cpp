
#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

Fixed::Fixed() : _rawBits(0), _fb(8)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src) : _rawBits(0), _fb(8)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = src.getRawBits();
	return ;
}

Fixed::Fixed(int const raw) : _rawBits(0), _fb(8)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = raw << this->_fb;
	return ;
}

Fixed::Fixed(float const floating_point) : _rawBits(0), _fb(8)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(floating_point * pow(2, this->_fb));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed		&Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

int			Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void		Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return ;
}

int			Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fb);
}
float		Fixed::toFloat(void) const
{
	return (this->_rawBits * pow(2, -this->_fb));
}

std::ostream			&operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}