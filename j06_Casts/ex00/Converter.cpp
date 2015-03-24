// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Converter.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 08:45:05 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/24 12:23:32 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <limits>
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
	std::cout << this->_mainType << std::endl;
	// if (this->_mainType)
	
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

	if (cpy == "nan" || cpy == "+inf" || cpy == "-inf")
		return (10);
	else if (cpy == "nanf" || cpy == "+inff" || cpy == "-inff")
		return (8);
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
	
	return (type);
}

void						Converter::detectFloat(std::string cpy)
{
	(void)cpy;
	return ;
}
void						Converter::detectDouble(std::string cpy)
{
	(void)cpy;
	return ;
}


void						Converter::describeAsChar(void)
{
	std::cout << "char: ";
	if (this->_mainType == 0 || this->_mainType >= 8 ||
		(this->_mainType >= 5 && (this->_asInt < 0 || this->_asInt > 0177)))
		std::cout << "impossible" << std::endl;
	else
	{
		if (this->_mainType >= 5)
			this->_asChar = static_cast<char>(this->_asInt);
		if (this->_asChar >= ' ' && this->_asChar <= '~')
			std::cout << this->_asChar << std::endl;
		else
		{
			std::cout << "'";
			if (this->_asChar == '\a')
				std::cout << "\\a";
			else if (this->_asChar == '\b')
				std::cout << "\\b";
			else if (this->_asChar == '\f')
				std::cout << "\\f";
			else if (this->_asChar == '\n')
				std::cout << "\\n";
			else if (this->_asChar == '\r')
				std::cout << "\\r";
			else if (this->_asChar == '\t')
				std::cout << "\\t";
			else if (this->_asChar == '\v')
				std::cout << "\\v";
			else if (this->_asChar == '\\')
				std::cout << "\\\\";
			else if (this->_asChar == '\'')
				std::cout << "\\'";
			else if (this->_asChar == '\"')
				std::cout << "\\\"";
			else if (this->_asChar == '\?')
				std::cout << "\\?";
			else
				std::cout << '\\' << std::oct << (int)this->_asChar;
			std::cout << "'" << std::endl;
		}
	}
	return ;
}
void						Converter::describeAsInt(void)
{
	std::cout << "int: ";
	if (this->_mainType <= 4)
		this->_asInt = static_cast<int>(this->_asChar);
	if (this->_mainType >= 8)
		std::cout << "impossible";
	else
		std::cout << std::dec << this->_asInt;
	std::cout << std::endl;
	return ;
}
void						Converter::describeAsFloat(void)
{
	std::cout << "float: ";
	
	std::cout << std::endl;
	return ;
}
void						Converter::describeAsDouble(void)
{
	std::cout << "double: ";
	
	std::cout << std::endl;
	return ;
}


// ******************* NESTED_CLASSES *** NESTED_CLASSES *** NESTED_CLASSES * //
