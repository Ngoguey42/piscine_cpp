
#include <iostream>
#include "Bureaucrat.hpp"

void					test1(Bureaucrat &b, Bureaucrat &bo)
{
	try
	{
		std::cout << "bo.decrementGrade + 1" << std::endl;		
		bo.decrementGrade();
		std::cout << bo << std::endl;
		std::cout << "bo.incrementGrade - 1" << std::endl;		
		bo.incrementGrade();
		std::cout << bo << std::endl;

		std::cout << "bo.incrementGrade - 1" << std::endl;		
		bo.incrementGrade();
		std::cout << bo << std::endl;

	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catched GradeTooLowException: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	(void)b;
	(void)bo;
	return ;
}
void					test2(Bureaucrat &b, Bureaucrat &bo)
{
	try
	{

		std::cout << "b.incrementGrade - 1" << std::endl;		
		b.incrementGrade();
		std::cout << b << std::endl;		
		std::cout << "b.decrementGrade + 1" << std::endl;		
		b.decrementGrade();
		std::cout << b << std::endl;
		std::cout << "b.decrementGrade + 1" << std::endl;		
		b.decrementGrade();
		std::cout << b << std::endl;

	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catched GradeTooLowException: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	(void)b;
	(void)bo;
	return ;
}

void						test3()
{
	try
	{
		std::cout << "Creating Bureaucrat @ grade 0" << std::endl;
		Bureaucrat b("Relou", 0);
		
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << "Catched GradeTooLowException: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	try
	{
		std::cout << "Creating Bureaucrat @ grade 151" << std::endl;		
		Bureaucrat b("Relou", 151);
		
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << "Catched GradeTooHighException: " << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
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

	std::cout << b << std::endl;
	std::cout << bo << std::endl;
	std::cout << std::endl;

	test1(b, bo);
	test2(b, bo);
	test3();

	
	return (0);
}
