// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.tpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/14 11:46:15 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 12:49:51 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

//#include <iostream>
#include "mutantstack.hpp"

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
template <typename T>
MutantStack<T>::MutantStack()
{
	std::cout << "[MutantStack]() Ctor called" << std::endl;
	return ;
}
template <typename T>
MutantStack<T>::MutantStack(MutantStack<T> const &src)
{
	std::cout << "[MutantStack](MutantStack const &) Ctor called" << std::endl;
	(void)src;
	return ;
}

// * DESTRUCTORS ************************************************************ //
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "[MutantStack] Dtor called" << std::endl;
	return ;
}

// * OPERATORS ************************************************************** //
template<typename T>
MutantStack<T>				&MutantStack<T>::operator=(
	MutantStack<T> const &rhs)
{
	std::cout << "[MutantStack] operator = called" << std::endl;	
	std::stack<T>::operator=(rhs);
	return (*this);
}

// * GETTERS **************************************************************** //
// * SETTERS **************************************************************** //
// * MEMBER FUNCTIONS / METHODS ********************************************* //
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	
	return (iterator());
}
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	typename MutantStack<T>::iterator	it;

	it.setPtr(&this->top() + 1);
	
	return (it);
	
}

// * NESTED_CLASSES ********************************************************* //

// * CTORS / DTORS ************** //
template <typename T>
MutantStack<T>::iterator::iterator()
{
	std::cout << "[MutantStack::iterator]() Ctor called" << std::endl;
	return ;
}
template <typename T>
MutantStack<T>::iterator::~iterator()
{
	std::cout << "[MutantStack::iterator] Dtor called" << std::endl;
	return ;
}
template <typename T>
MutantStack<T>::iterator::iterator(
	typename MutantStack<T>::iterator const &src)
{
	std::cout <<
		"[MutantStack::iterator](MutantStack::iterator const &) Ctor called" <<
		std::endl;
	(void)src;
	return ;
}
	// * OPERATORS ****************** //
template<typename T>
typename MutantStack<T>::iterator	&MutantStack<T>::iterator::operator=(
	typename MutantStack<T>::iterator const &rhs)
{
	std::cout << "[MutantStack::iterator] operator = called" << std::endl;	
	std::iterator<std::bidirectional_iterator_tag, T>::operator=(rhs);
	_ptr = rhs._ptr;
	return (*this);
}
template<typename T>
T							MutantStack<T>::iterator::operator*(void)
{
	return (*_ptr);
}
	// * MEMBER FUNCTIONS / METHODS * //
template<typename T>
void						MutantStack<T>::iterator::setPtr(
	T *ptr)
{
	this->_ptr = ptr;
	return ;
}
