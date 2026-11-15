/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 16:53:31 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/14 19:53:17 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Unnamed")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::performAction() const
{
	std::string	filename = _target + "_shrubbery";
	std::ofstream	file(filename.c_str()); //creates and opens a file
	if (!file)
		throw std::runtime_error("Could not open shrubbery file");
	file << "       *                           *     \n"
		 << "      ***             *           ***    \n"
		 << "     *****           ***         *****   \n"
		 << "    *******         *****       *******  \n"
		 << "   *********       *******     ********* \n"
		 << "      |||            |||          |||    \n"
		 << "      |||            |||          |||    \n";

	file.close();
	if (!file)
		throw std::runtime_error("Could not write shrubbery file");
}