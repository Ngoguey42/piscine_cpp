// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Converter.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 08:45:05 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 18:21:47 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <sstream>
#include <cmath>
#include <limits>
#include <iomanip>
#include <string>
#include "Converter.hpp"

// **************************************** STATICS *** STATICS *** STATICS * //
// ************************* CONSTRUCTORS *** CONSTRUCTORS *** CONSTRUCTORS * //
Converter::Converter(std::string const &str) :
	_ref(str),
	_asChar(0),
	_asInt(0),
	_asFloat(0.),
	_asDouble(0.),
	_mainType(0)
{
	this->_mainType = this->detectCharMainType();
	if (this->_mainType == 0)
		this->_mainType = this->detectIntMainType();
	if (this->_mainType == 0)
		this->_mainType = this->detectFloatDoubleMainType();
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
	{
		this->_asChar = this->_ref[0];
		return (std::isdigit(this->_ref[0]) ? 0 : 1);
	}
	else if (this->_ref.length() == 2 && this->_ref[0] == '\\' && 
			 std::strspn(this->_ref.c_str(), "abfnrtv\\\'\"\?") == 2)
	{
		if (this->_ref == "\\a")
			this->_asChar = '\a';
		else if (this->_ref == "\\b")
			this->_asChar = '\b';
		else if (this->_ref == "\\f")
			this->_asChar = '\f';
		else if (this->_ref == "\\n")
			this->_asChar = '\n';
		else if (this->_ref == "\\r")
			this->_asChar = '\r';
		else if (this->_ref == "\\t")
			this->_asChar = '\t';
		else if (this->_ref == "\\v")
			this->_asChar = '\v';
		else if (this->_ref == "\\\\")
			this->_asChar = '\\';
		else if (this->_ref == "\\\'")
			this->_asChar = '\'';
		else if (this->_ref == "\\\"")
			this->_asChar = '\"';
		else if (this->_ref == "\\?")
			this->_asChar = '\?';
		return (2);
	}

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
		this->_asChar = static_cast<char>(nbr);
		if (hexa)
			return (4);
		return (3);
	}
	return (0);
}

int							Converter::detectIntMainType()
{
	int				type = 5;
	std::string		cpy(this->_ref);
	int				nbr = 0;
	int				sign = 1;
	int				multiplier = 10;
	int				curNbr;
	
	if (cpy[0] == '0')
	{
		type = 6;
		multiplier = 8;
		cpy = cpy.substr(1);
		if (cpy[0] == 'x')
		{
			type = 7;
			multiplier = 16;
			cpy = cpy.substr(1);
		}
	}
	else if (cpy[0] == '-' || cpy[0] == '+')
	{
		if (cpy[0] == '-')
			sign = -1;
		cpy = cpy.substr(1);
	}	
	if ((cpy.length() == 0 && type != 6) ||
		(type == 6 && std::strspn(cpy.c_str(), "01234567") !=
		 cpy.length()) ||
		(type == 7 && std::strspn(cpy.c_str(), "0123456789abcdefABCDEF") !=
		 cpy.length()) ||
		(type == 5 && std::strspn(cpy.c_str(), "0123456789") !=
		 cpy.length()))
		return (0);
	while (cpy[0] != '\0')
	{
		curNbr = convertCharToNumber(cpy[0]);
		if (sign == -1 &&
			std::numeric_limits<int>::min() - nbr * multiplier + curNbr > 0)
			return (0);
		else if (sign == 1 &&
				 std::numeric_limits<int>::max() - nbr * multiplier - curNbr < 0)
			return (0);
		nbr = nbr * multiplier + sign * curNbr;
		cpy = cpy.substr(1);
	}
	this->_asInt = nbr;
	return (type);
}
int							Converter::detectFloatDoubleMainType()
{
	int				type = 11;
	std::string		cpy(this->_ref);

	
	if (cpy == "nan"|| cpy == "NAN")
	{
		this->_asDouble = NAN;
		return (10);
	}
	if (cpy == "nanf"|| cpy == "NANf")
	{
		this->_asFloat = NAN;
		return (8);
	}
	if (cpy == "+inf"|| cpy == "+INF")
	{
		this->_asDouble = 1./0.;
		return (10);
	}
	if (cpy == "+inff"|| cpy == "+INFf")
	{
		this->_asFloat = 1./0.;
		return (8);
	}
	if (cpy == "-inf"|| cpy == "-INF")
	{
		this->_asDouble = -1./0.;
		return (10);
	}
	if (cpy == "-inff"|| cpy == "-INFf")
	{
		this->_asFloat = -1./0.;
		return (8);
	}
	if (cpy[cpy.length() - 1] == 'f')
	{
		type -= 2;
		cpy.resize(cpy.length() - 1);
	}
	if (cpy.find('.') == std::string::npos ||
		cpy.find_first_of('.') != cpy.find_last_of('.'))
		return (0);
	if (cpy.find_first_not_of("0123456789.", 1) != std::string::npos ||
		cpy.find_first_not_of("0123456789.+-") != std::string::npos)
		return (0);
	if (type == 11)
		return (detectDouble(cpy));
	return (detectFloat(cpy));
}

int							Converter::detectFloat(std::string cpy)
{
	std::istringstream	iss;

	iss.str(cpy);
	iss.clear();
	iss >> this->_asFloat;
	if (iss.fail())
		return (0);
	return (9);
}
int							Converter::detectDouble(std::string cpy)
{
	std::istringstream	iss;

	iss.str(cpy);
	iss.clear();
	iss >> this->_asDouble;
	if (iss.fail())
		return (0);
	return (11);
}


static void					printTruc(char c)
{
	std::cout << "'";
	if (c >= ' ' && c <= '~')
		std::cout << c;
	else if (c == '\a')
		std::cout << "\\a";
	else if (c == '\b')
		std::cout << "\\b";
	else if (c == '\f')
		std::cout << "\\f";
	else if (c == '\n')
		std::cout << "\\n";
	else if (c == '\r')
		std::cout << "\\r";
	else if (c == '\t')
		std::cout << "\\t";
	else if (c == '\v')
		std::cout << "\\v";
	else if (c == '\\')
		std::cout << "\\\\";
	else if (c == '\'')
		std::cout << "\\'";
	else if (c == '\"')
		std::cout << "\\\"";
	else if (c == '\?')
		std::cout << "\\?";
	else
		std::cout << '\\' << std::oct << static_cast<int>(c);
	std::cout << "'";
	return ;
}

void						Converter::describeAsChar(void)
{
	std::cout << "char: ";
	if (this->_mainType == 0 || this->_mainType == 8 || this->_mainType == 10)
		std::cout << "impossible";
	else if (this->_mainType >= 5)
	{
		if (this->_mainType == 9)
			this->_asInt = static_cast<int>(this->_asFloat);
		else if (this->_mainType == 11)
			this->_asInt = static_cast<int>(this->_asDouble);
		if (this->_asInt >= 0 && this->_asInt <= 0177)
			printTruc(static_cast<char>(this->_asInt));
		else
			std::cout << "impossible";
	}
	else
		printTruc(_asChar);
	std::cout << std::endl;
	return ;
}
void						Converter::describeAsInt(void) const
{
	std::cout << "int: ";
	if (this->_mainType <= 4 && this->_mainType > 0)
		std::cout << static_cast<int>(this->_asChar);
	else if (
		this->_mainType == 9 &&
		this->_asFloat > static_cast<float>(std::numeric_limits<int>::min()) &&
		this->_asFloat < static_cast<float>(std::numeric_limits<int>::max()))
		std::cout << static_cast<int>(this->_asFloat);
	else if (
		this->_mainType == 11 &&
		this->_asDouble > static_cast<double>(std::numeric_limits<int>::min()) &&
		this->_asDouble < static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << static_cast<int>(this->_asDouble);
	else if (this->_mainType <= 7 && this->_mainType > 0)
		std::cout << std::dec << this->_asInt;
	else
		std::cout << "impossible";
	std::cout << std::endl;
	return ;
}
void						Converter::describeAsFloat(void) const
{
	std::cout << "float: ";
	std::cout.setf(std::ios_base::showpoint);
	if (this->_mainType >= 10)
		std::cout << static_cast<float>(this->_asDouble) << 'f';
	else if (this->_mainType >= 8)
		std::cout << _asFloat << 'f';
	else if (this->_mainType >= 5)
		std::cout << static_cast<float>(this->_asInt) << 'f';
	else if (this->_mainType >= 1)
		std::cout << static_cast<float>(this->_asChar) << 'f';
	else
		std::cout << "impossible";
	std::cout << std::endl;
	return ;
}
void						Converter::describeAsDouble(void) const
{
	std::cout << "double: ";
	std::cout.setf(std::ios_base::showpoint);
	if (this->_mainType >= 10)
		std::cout << _asDouble;
	else if (this->_mainType >= 8)
		std::cout << static_cast<double>(this->_asFloat);
	else if (this->_mainType >= 5)
		std::cout << static_cast<double>(this->_asInt);
	else if (this->_mainType >= 1)
		std::cout << static_cast<double>(this->_asChar);
	else
		std::cout << "impossible";
	std::cout << std::endl;
	return ;
}


// ******************* NESTED_CLASSES *** NESTED_CLASSES *** NESTED_CLASSES * //
