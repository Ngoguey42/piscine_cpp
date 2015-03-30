// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 10:50:27 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 12:11:26 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

//# include <string>
class Form;
# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Bureaucrat
{
public:
	static const int			highestGrade;
	static const int			lowestGrade;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &src);
		
		virtual const char *what() const throw();
	private:
		GradeTooHighException& operator=(GradeTooHighException const &rhs);
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &src);

		virtual const char *what() const throw();
	private:
		GradeTooLowException& operator=(GradeTooLowException const &rhs);
	};

	virtual ~Bureaucrat();
	Bureaucrat(std::string const &name, int startGrade)
		throw(GradeTooHighException, GradeTooLowException);

	void						incrementGrade(void)
		throw(GradeTooHighException);
	void						decrementGrade(void)
		throw(GradeTooLowException);
	void						signForm(Form &f);
	
	const std::string			&getName(void) const;
	int							getGrade(void) const;

private:
	Bureaucrat					&operator=(Bureaucrat const &rhs);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat();

	const std::string			_name;
	int							_grade;
};
std::ostream					&operator<<(std::ostream &o,
											Bureaucrat const &rhs);

#endif // **************************************************** BUREAUCRAT_HPP //
