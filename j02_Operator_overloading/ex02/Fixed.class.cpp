
#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

Fixed::Fixed() : _rawBits(0), _fb(8)
{
	return ;
}

Fixed::Fixed(Fixed const & src) : _rawBits(0), _fb(8)
{
	this->_rawBits = src.getRawBits();
	return ;
}

Fixed::Fixed(int const raw) : _rawBits(0), _fb(8)
{
	this->_rawBits = raw << this->_fb;
	return ;
}

Fixed::Fixed(float const floating_point) : _rawBits(0), _fb(8)
{
	this->_rawBits = (int)roundf(floating_point * (float)(1 << this->_fb));
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed			&Fixed::operator=(Fixed const & rhs)
{
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

/*
** The subject says that the 'number of fractional' bits "will always be the litteral 8."
** On the other hand there is no getter to retreive rhs's 'number of fractional'.
** I could use toInt() function but I will just do a raw comparison of _rawBits.
*/
bool			Fixed::operator>(Fixed const & rhs) const{return (this->_rawBits > rhs.getRawBits());}
bool			Fixed::operator<(Fixed const & rhs) const{return (this->_rawBits < rhs.getRawBits());}
bool			Fixed::operator>=(Fixed const & rhs) const{return (this->_rawBits >= rhs.getRawBits());}
bool			Fixed::operator<=(Fixed const & rhs) const{return (this->_rawBits <= rhs.getRawBits());}
bool			Fixed::operator==(Fixed const & rhs) const{return (this->_rawBits == rhs.getRawBits());}
bool			Fixed::operator!=(Fixed const & rhs) const{return (this->_rawBits != rhs.getRawBits());}
Fixed const		&Fixed::max(Fixed const &f1, Fixed const &f2)
{return (f1.getRawBits() > f2.getRawBits() ? f1 : f2);}
Fixed const		&Fixed::min(Fixed const &f1, Fixed const &f2)
{return (f1.getRawBits() < f2.getRawBits() ? f1 : f2);}

Fixed			Fixed::operator+(Fixed const & rhs) const{return Fixed(this->toFloat() + rhs.toFloat());}
Fixed			Fixed::operator-(Fixed const & rhs) const{return Fixed(this->toFloat() - rhs.toFloat());}
Fixed			Fixed::operator*(Fixed const & rhs) const{return Fixed(this->toFloat() * rhs.toFloat());}
Fixed			Fixed::operator/(Fixed const & rhs) const{return Fixed(this->toFloat() / rhs.toFloat());}
Fixed			&Fixed::operator++(void){this->_rawBits++; return (*this);}
Fixed			Fixed::operator++(int){Fixed	cpy(*this); this->_rawBits++; return (cpy);}

int				Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void			Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

int				Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fb);
}
float			Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << this->_fb));
}

std::ostream	&operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}
