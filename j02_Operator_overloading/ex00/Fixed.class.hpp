// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Fixed.class.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/08 12:28:48 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/09 06:33:41 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const & src);
	Fixed				&operator=(Fixed const & rhs);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
private:
	static int const	_fb;
	int					_rawBits;
};

#endif
