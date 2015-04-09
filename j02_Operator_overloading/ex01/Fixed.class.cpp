// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 12:35:08 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 06:37:30 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

int const					Fixed::_fb = 8;

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src) : _rawBits(0)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = src.getRawBits();
	return ;
}

Fixed::Fixed(int const raw) : _rawBits(0)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = raw << Fixed::_fb;
	return ;
}

Fixed::Fixed(float const floating_point) : _rawBits(0)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(floating_point * (float)(1 << Fixed::_fb));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed			&Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

int				Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void			Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return ;
}

int				Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_fb);
}
float			Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << Fixed::_fb));
}

std::ostream	&operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
