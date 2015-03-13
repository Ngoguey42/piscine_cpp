// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bureaucrat.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/03/13 10:50:27 by ngoguey           #+#    #+#             //
//   Updated: 2015/03/13 14:47:49 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

//# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat
{
public:
	Bureaucrat(Bureaucrat const &src);
	virtual ~Bureaucrat();
	Bureaucrat					&operator=(Bureaucrat const &rhs);

	Bureaucrat(std::string const &name, int startGrade);
	
	static const int			highestGrade;
	static const int			lowestGrade;

	void						incrementGrade(void);
	void						decrementGrade(void);

	const std::string			&getName(void) const;
	int							getGrade(void) const;

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException() throw();
		virtual ~GradeTooHighException() throw();
		GradeTooHighException(GradeTooHighException const &src) throw();
		GradeTooHighException& operator=(GradeTooHighException const &rhs) throw();

		virtual const char *what() const throw();		
	private:
	};
	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException() throw();
		virtual ~GradeTooLowException() throw();
		GradeTooLowException(GradeTooLowException const &src) throw();
		GradeTooLowException& operator=(GradeTooLowException const &rhs) throw();

		virtual const char *what() const throw();		
	private:
	};
	
protected:
private:
	Bureaucrat();
	
	const std::string			_name;
	int							_grade;
};
std::ostream					&operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif // **************************************************** BUREAUCRAT_HPP //
