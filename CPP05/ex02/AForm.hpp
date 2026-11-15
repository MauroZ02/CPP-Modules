/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:58:07 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/14 17:43:23 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool			_isSigned;
	const int		_gradeToSign;
	const int		_gradeToExecute;

protected:
	virtual void	performAction() const = 0;

public:
	AForm();
	AForm(const std::string &name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm &other);
	AForm	&operator=(const AForm &other);
	virtual ~AForm();

	void	beSigned(const Bureaucrat &bureaucrat);

	std::string	getName() const;
	bool	getSigned() const;
	int		getGradeToSign() const;
	int		getGradeToExecute() const;
	void	execute(const Bureaucrat &executor) const;

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

	class	NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const AForm &Aform);



#endif