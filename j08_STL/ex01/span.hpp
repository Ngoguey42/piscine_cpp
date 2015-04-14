// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 16:54:03 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 09:47:20 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SPAN_HPP
# define SPAN_HPP

//# include <string>
# include <iostream>
# include <vector>
# include <vector>

//# include <stdexcept>

class Span
{
public:
	Span(unsigned int maxSize);
	virtual ~Span();

	unsigned int				getSize(void) const;
	unsigned int				getMaxSize(void) const;

	void						addNumber(int i);
	unsigned int				shortestSpan(void);	
	unsigned int				longestSpan(void);	

	void						merge(std::vector<int>::const_iterator begin,
									  std::vector<int>::iterator const &end);

protected:
private:

	std::vector<int>			_vector;
	unsigned int				_size;
	unsigned int				_maxSize;

	unsigned int				_minSpan;
	unsigned int				_maxSpan;
	bool						_refresh;
	std::vector<unsigned int>	_adjDiff;

	Span();
	Span(Span const &src);
	Span						&operator=(Span const &rhs);
};
std::ostream					&operator<<(std::ostream &o, Span const &rhs);

#endif // ********************************************************** SPAN_HPP //
