// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Form.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 16:06:23 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/30 14:33:46 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FORM_HPP
# define FORM_HPP

class Bureaucrat;
# include "Bureaucrat.hpp"
# include <iostream>
# include <stdexcept>

class Form
{
public:
	static const int			highestGrade;
	static const int			lowestGrade;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException();
		GradeTooHighException(GradeTooHighException const &src);
		virtual ~GradeTooHighException() throw();

		virtual const char *what() const throw();
	private:
		GradeTooHighException& operator=(GradeTooHighException const &rhs);
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException();
		GradeTooLowException(GradeTooLowException const &src);
		virtual ~GradeTooLowException() throw();

		virtual const char *what() const throw();
	private:
		GradeTooLowException& operator=(GradeTooLowException const &rhs);
	};
	class FormNotSignedException : public std::exception
	{
	public:
		FormNotSignedException();
		FormNotSignedException(FormNotSignedException const &src);
		virtual ~FormNotSignedException() throw();

		virtual const char *what() const throw();
	private:
		FormNotSignedException& operator=(FormNotSignedException const &rhs);
	};

	virtual ~Form();
	Form(std::string const &name, int sGrade, int eGrade,
		 std::string const &target)
		throw(GradeTooHighException, GradeTooLowException);

	std::string const			&getName(void) const;
	int							getSGrade(void) const;
	int							getEGrade(void) const;
	bool						getIsSigned(void) const;
	std::string const			&getTarget(void) const;
	
	void						beSigned(Bureaucrat const &b)
		throw(GradeTooLowException);
	virtual void				tryExecute(Bureaucrat const &executor) const
		throw(GradeTooLowException, FormNotSignedException);
protected:
	virtual void				execute(Bureaucrat const &executor) const = 0;
	
private:
	Form();
	Form(Form const &src);
	Form						&operator=(Form const &rhs);

	std::string const			_name;
	int const					_sGrade;
	int const					_eGrade;
	bool						_isSigned;
	std::string const			_target;
};
std::ostream					&operator<<(std::ostream &o, Form const &rhs);

#endif // ********************************************************** FORM_HPP //
