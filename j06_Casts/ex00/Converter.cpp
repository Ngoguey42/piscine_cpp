// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Converter.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 08:45:05 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/24 10:17:05 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

// #include <iostream>
#include <string>
#include "Converter.hpp"

// **************************************** STATICS *** STATICS *** STATICS * //
// ************************* CONSTRUCTORS *** CONSTRUCTORS *** CONSTRUCTORS * //
static int					convertCharToNumber(char c)
{
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (c - '0');
}

int							Converter::detectCharMainType()
{
	if (this->_ref.length() == 1 && std::isprint(this->_ref[0]))
		return (1);
	else if (this->_ref.length() == 2 && this->_ref[0] == '\\' && 
			 std::strspn(this->_ref.c_str(), "abfnrtv\\\'\"\?") == 2)
		return (2);
	else if (this->_ref.length() > 1 && this->_ref[0] == '\\')
	{
		std::string		cpy(this->_ref.substr(1));
		bool			hexa = false;
		int				nbr = 0;

		if (cpy[0] == 'x')
		{
			hexa = true;
			cpy = cpy.substr(1);
			if (std::strspn(cpy.c_str(), "0123456789abcdefABCDEF") != cpy.length())
				return (0);
		}
		else if (std::strspn(cpy.c_str(), "01234567") != cpy.length())
			return (0);
		while (cpy[0] != '\0' && nbr < 1000)
		{
			nbr = nbr * (hexa ? 16 : 8) + convertCharToNumber(cpy[0]);
			cpy = cpy.substr(1);
		}
		if (nbr > 0x7F)
			return (0);
		this->_involvedInteger = nbr;
		if (hexa)
			return (4);
		return (3);
	}
	return (0);
}

Converter::Converter(std::string const &str) :
	_ref(str),
	_mainType(0)
{
	this->_mainType = this->detectCharMainType();
	// if (this->_mainType == 0)
		// ;
	std::cout << this->_mainType << std::endl;
	
	return ;
}

// **************************** DESTRUCTORS *** DESTRUCTORS *** DESTRUCTORS * //
Converter::~Converter()
{
	// std::cout << "[Converter]() Dtor called" << std::endl;
	return ;
}

// ********************************** OPERATORS *** OPERATORS *** OPERATORS * //
// **************************************** GETTERS *** GETTERS *** GETTERS * //
// **************************************** SETTERS *** SETTERS *** SETTERS * //
// ********************************** FUNCTIONS *** FUNCTIONS *** FUNCTIONS * //
void						Converter::describeAsChar(void) const
{
	return ;
}
void						Converter::describeAsInt(void) const
{
	return ;
}
void						Converter::describeAsFloat(void) const
{
	return ;
}
void						Converter::describeAsDouble(void) const
{
	return ;
}


// ******************* NESTED_CLASSES *** NESTED_CLASSES *** NESTED_CLASSES * //
