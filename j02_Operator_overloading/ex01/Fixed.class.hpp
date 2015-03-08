
#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const & src);
	Fixed(int const raw);
	Fixed(float const raw);
	Fixed				&operator=(Fixed const & rhs);
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
private:
	int					_rawBits;
	int const			_fb;
};

std::ostream			&operator<<(std::ostream & o, Fixed const & rhs);

#endif
