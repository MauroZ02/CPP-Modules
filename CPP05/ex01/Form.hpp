/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:58:07 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/13 00:43:57 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool			_isSigned;
	const int		_gradeToSign;
	const int		_gradeToExecute;

public:
	Form();
	Form(const std::string &name, const int gradeToSign, const int gradeToExecute);
	Form(const Form &other);
	Form	&operator=(const Form &other);
	~Form();

	void	beSigned(const Bureaucrat &bureaucrat);

	std::string	getName() const;
	bool	getSigned() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Form &form);



#endif