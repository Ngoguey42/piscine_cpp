
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
	bool				operator>(Fixed const & rhs) const;
	bool				operator<(Fixed const & rhs) const;
	bool				operator>=(Fixed const & rhs) const;
	bool				operator<=(Fixed const & rhs) const;
	bool				operator==(Fixed const & rhs) const;
	bool				operator!=(Fixed const & rhs) const;
	Fixed				operator+(Fixed const & rhs) const;
	Fixed				operator-(Fixed const & rhs) const;
	Fixed				operator*(Fixed const & rhs) const;
	Fixed				operator/(Fixed const & rhs) const;
	Fixed				&operator++(void);
	Fixed				operator++(int);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	
	static Fixed const	&max(Fixed const &f1, Fixed const &f2);
	static Fixed const	&min(Fixed const &f1, Fixed const &f2);
private:
	int					_rawBits;
	int const			_fb;
};

std::ostream			&operator<<(std::ostream & o, Fixed const & rhs);

#endif
