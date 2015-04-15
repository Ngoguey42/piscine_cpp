// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Array.template.hpp                                 :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 08:17:18 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/15 10:16:32 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ARRAY_TEMPLATE_HPP
# define ARRAY_TEMPLATE_HPP

//# include <string>
# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
public:
	// * CTORS / DTORS ************** //
	Array<T>()
		{
			std::cout << "Ctor() called" << std::endl;
			this->_array = new T[0];
			this->_size = 0;
			return ;
		}
	Array<T>(Array<T> const &src)
		{
			std::cout << "Ctor(Array<T> const &) called" << std::endl;
			this->_size = src.size();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = src[i];
			return ;
		}
	Array<T>(unsigned int n)
		{
			T		*def = new T();

			std::cout << "Ctor(unsigned int) called" << std::endl;
			this->_array = new T[n];
			this->_size = n;
			while (n-- > 0)
				this->_array[n] = *def;
			delete def;
			return ;
		}
	virtual ~Array()
		{
			std::cout << "~Dtor() called" << std::endl;
			delete _array;
		}

	// * OPERATORS ****************** //
	T							&operator[](unsigned int i)
		throw(std::exception)
		{
			if (i >= this->_size)
				throw std::out_of_range("Accessing an out of range index");
			return (this->_array[i]);
		}	
	T const						&operator[](unsigned int i) const
		throw(std::exception)
		{
			if (i >= this->_size)
				throw std::out_of_range("Accessing an out of range index");
			return (this->_array[i]);
		}	
	Array						&operator=(Array<T> const &rhs)
		{
			std::cout << "operator = called" << std::endl;
			delete this->_array;
			this->_size = rhs.size();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->_size; i++)
				this->_array[i] = rhs[i];
			return (*this);
		}
	// * MEMBER FUNCTIONS / METHODS * //
	unsigned int				size(void) const {return this->_size;}
	
protected:
private:
	// * ATTRIBUTES ***************** //
	T							*_array;
	unsigned int				_size;
};

#endif // ************************************************ ARRAY_TEMPLATE_HPP //
