// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   span.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/13 16:59:08 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 10:42:39 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <cstdlib>
#include <numeric>
#include "span.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
Span::Span(unsigned int maxSize) :
	_vector(0),
	_size(0),
	_maxSize(maxSize),
	_minSpan(0),
	_maxSpan(0),
	_refresh(true),
	_adjDiff()
{
	std::cout << "[Span](unsigned int) Ctor called" << std::endl;
	return ;
}

// * DESTRUCTORS ************************************************************ //
Span::~Span()
{
	std::cout << "[Span]() Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
std::ostream				&operator<<(std::ostream &o, Span const &rhs)
{
	return (o << "Span: " << rhs.getSize() << "/" << rhs.getMaxSize());
}

// * GETTERS **************************************************************** //
unsigned int				Span::getSize(void) const{return this->_size;}
unsigned int				Span::getMaxSize(void) const{return this->_maxSize;}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
static unsigned int			customDiff(int rhs, int lhs)
{
	if (rhs > lhs)
		return (rhs - lhs);
	return (lhs - rhs);
}

void						Span::addNumber(int i)
{
	if (_size >= _maxSize)
		throw std::logic_error("The vector is full");
	_vector.push_back(i);
	_size++;
	_refresh = true;
	return ;
}
void						Span::addNumber(std::vector<int>::const_iterator begin,
											std::vector<int>::iterator const &end)
{
	while (_size < _maxSize && begin != end)
	{
		_vector.push_back(*begin);
		_size++;
		_refresh = true;
		begin++;
	}
	if (begin == end)
		std::cout << "Vector merged successfully !" << std::endl;
	else
		std::cout << "Could not fully merge vector" << std::endl;
	return ;
}

unsigned int				Span::shortestSpan(void)
{

	if (_size <= 1)
		throw std::logic_error("Not enough values in vector");
	if (_refresh)
	{
		_adjDiff.clear();
		_adjDiff.resize(_size);
		std::adjacent_difference(_vector.begin(), _vector.end(),
								 _adjDiff.begin(), &customDiff);
		_adjDiff.erase(_adjDiff.begin());
		_minSpan = *std::min_element(_adjDiff.begin(), _adjDiff.end());
		_maxSpan = *std::max_element(_adjDiff.begin(), _adjDiff.end());
		_refresh = false;
	}
	return (_minSpan);
}
unsigned int				Span::longestSpan(void)
{
	if (_size <= 1)
		throw std::logic_error("Not enough values in vector");
	if (_refresh)
	{
		_adjDiff.clear();
		_adjDiff.resize(_size);
		std::adjacent_difference(_vector.begin(), _vector.end(),
								 _adjDiff.begin(), &customDiff);
		_adjDiff.erase(_adjDiff.begin());
		_minSpan = *std::min_element(_adjDiff.begin(), _adjDiff.end());
		_maxSpan = *std::max_element(_adjDiff.begin(), _adjDiff.end());
		_refresh = false;
	}
	return (_maxSpan);
}

// * NESTED_CLASSES ********************************************************* //
