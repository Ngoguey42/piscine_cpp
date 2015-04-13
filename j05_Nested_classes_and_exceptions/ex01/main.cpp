// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/30 11:58:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/04/13 12:54:15 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

void					test1(Bureaucrat &b, Form &f)
{
	std::cout << "\033[35mtest1: \033[0m" << std::endl;
	
	std::cout << b.getName() << "(" << b.getGrade() <<
		") trying to sign " << f.getName() << "(" << f.getSGrade() <<
		")" << std::endl;
	b.signForm(f);
	std::cout << std::endl;
	return ;
}

void						test3()
{
	try
	{
		std::cout << "Creating Form @ grade 0, 10" << std::endl;
		Form b("Test", 0, 10);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Catched GradeTooLowException: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Creating Form @ grade 10, 151" << std::endl;
		Form b("Test", 10, 151);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << "Catched GradeTooLowException: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	
	return ;
}



int							main(void)
{
	Bureaucrat		b("Connard", Bureaucrat::lowestGrade);
	Bureaucrat		bo("Boss", Bureaucrat::highestGrade);
	Form			v("Paplard vert", 1, 150);
	Form			r("Paplard rouge", 150, 1);

	std::cout << b << std::endl;
	std::cout << bo << std::endl;
	std::cout << r << std::endl;
	std::cout << v << std::endl;
	std::cout << std::endl;

	test1(b, v);
	test1(bo, v);
	test1(b, r);
	test1(bo, r);
	test3();

	return (0);
}
