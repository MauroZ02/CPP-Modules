/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:58:03 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/13 00:43:26 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	:_name("Unnamed"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
}

Form::Form(const std::string &name, const int gradeToSign, const int gradeToExecute)
	:_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &other)
	:_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form()
{
}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

std::string	Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_isSigned);
}

int		Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int		Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

const char	*Form::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high");
}

const char	*Form::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << form.getName()
		<< ", signed: " << form.getSigned()
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExecute();
	return out;
}
