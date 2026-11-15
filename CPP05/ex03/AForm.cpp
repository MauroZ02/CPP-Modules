/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:58:03 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/13 00:43:26 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	:_name("Unnamed"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1)
{
}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute)
	:_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw (GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &other)
	:_name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute)
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm()
{
}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw (GradeTooLowException());
}

std::string	AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_isSigned);
}

int		AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int		AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::execute(const Bureaucrat &executor) const
{
	if (_isSigned == false)
		throw(NotSignedException());
	if (executor.getGrade() > _gradeToExecute)
		throw (GradeTooLowException());
	performAction();
}

const char	*AForm::GradeTooHighException::what() const throw ()
{
	return ("Grade is too high.");
}

const char	*AForm::GradeTooLowException::what() const throw ()
{
	return ("Grade is too low.");
}

const char	*AForm::NotSignedException::what() const throw ()
{
	return ("Form is not signed.");
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << Aform.getName()
		<< ", signed: " << Aform.getSigned()
		<< ", grade to sign: " << Aform.getGradeToSign()
		<< ", grade to execute: " << Aform.getGradeToExecute();
	return out;
}
