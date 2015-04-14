// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   mutantstack.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/04/14 11:22:58 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 14:02:56 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

//# include <string>
# include <iostream>
# include <stack>
//# include <stdexcept>

template <typename T>
class MutantStack : public std::stack<T> 
{
public:
	// * STATICS ******************** //
	// * NESTED OBJECTS ************* //
	class iterator : public std::iterator<std::bidirectional_iterator_tag, T>
	{
	public:
		iterator();
		iterator(iterator const &src);
		~iterator();
		iterator				&operator=(iterator const &rhs);
		bool					operator!=(iterator const &rhs);

		T						operator*(void);
		iterator				&operator++(void);
		iterator				operator++(int);
		iterator				&operator--(void);
		iterator				operator--(int);
		void					setPtr(T *ptr);
		void					printAdress(void);
		
	private:
		T						*_ptr;
		
	};
	
	// * CTORS / DTORS ************** //
	MutantStack<T>();
	~MutantStack<T>();
	MutantStack<T>(MutantStack<T> const &src);
	// * OPERATORS ****************** //
	MutantStack<T>				&operator=(MutantStack<T> const &rhs);
	// * GETTERS / SETTERS ********** //
	// * MEMBER FUNCTIONS / METHODS * //
	iterator					begin(void);
	iterator					end(void);
	
	// * ATTRIBUTES ***************** //
	
protected:
private:
};

//std::ostream					&operator<<(std::ostream &o, MutantStack const &rhs);

#include "mutantstack.tpp"

#endif // *************************************************** MUTANTSTACK_HPP //
