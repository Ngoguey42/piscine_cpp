// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/31 19:07:06 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/14 18:12:29 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

class Base
{
public:
	virtual ~Base() {};
};
class A : public Base{};
class B : public Base{};
class C : public Base{};

#include <iostream>

void						identify_from_pointer(Base *p)
{
	try
	{
		*p = dynamic_cast<A&>(*p);
		std::cout << "A" << std::endl;	
	}
	catch (const std::bad_cast&){}
	try
	{
		*p = dynamic_cast<B&>(*p);
		std::cout << "B" << std::endl;
	}
	catch (const std::bad_cast&){}
	try
	{
		*p = dynamic_cast<C&>(*p);
		std::cout << "C" << std::endl;	
	}
	catch (const std::bad_cast&){}
	return ;
}
void						identify_from_reference(Base &p)
{
	try
	{
		p = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;	
	}
	catch (const std::bad_cast&){}
	try
	{
		p = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::bad_cast&){}
	try
	{
		p = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;	
	}
	catch (const std::bad_cast&){}
	return ;
}


Base						*generate(void)
{
	if (std::rand() % 3 == 0)
	{
		std::cout << "creating an A" << std::endl;
		return (new A);
	}
	if (std::rand() % 2 == 0)
	{
		std::cout << "creating a B" << std::endl;
		return (new B);
	}
	std::cout << "creating a C" << std::endl;
	return (new C);
}


int							main(void)
{
	Base		*p;

	srand(time(NULL));
	std::cout << "From ptr then from ref" << std::endl;
	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);
	delete p;

	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);
	delete p;

	p = generate();
	identify_from_pointer(p);
	identify_from_reference(*p);
	delete p;
	return (0);
}
