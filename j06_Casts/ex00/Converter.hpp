// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Converter.hpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/24 08:37:50 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/24 11:12:24 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

// # include <string>
# include <iostream>
//# include <stdexcept>

class Converter
{
public:
	Converter(std::string const &src);
	virtual ~Converter();
	void						describeAsChar(void) const;
	void						describeAsInt(void) const;
	void						describeAsFloat(void) const;
	void						describeAsDouble(void) const;
	
protected:
private:
	std::string const			_ref;
	char						_asChar;
	int							_asInt;
	float						_asFloat;
	double						_asDouble;
	int							_mainType;
/*
** 0none
** 1char letter, 2char escape letter, 3char escape octal, 4char escape hex
** 5int decimal, 6 int octal, 7 int hexadecimal
** 8txt float, 9nbr float
** 10txt double, 10nbr double
*/	

	int							detectCharMainType(void);
	int							detectIntMainType(void);
	int							detectFloatDoubleMainType(void);


	
	Converter();
	Converter(Converter const &src);
	Converter					&operator=(Converter const &rhs);
};
//std::ostream					&operator<<(std::ostream &o, Converter const &rhs);

#endif // ***************************************************** CONVERTER_HPP //
