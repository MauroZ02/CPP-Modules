/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:10:16 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/14 21:34:33 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	Intern intern;
	Bureaucrat chief("Chief", 1);
	AForm *form;

	std::cout << "--- Shrubbery ---\n";
	form = intern.makeForm("shrubbery creation", "garden");
	if (form)
	{
		std::cout << *form << '\n';
		chief.signForm(*form);
		chief.executeForm(*form);
		delete form;
	}

	std::cout << "\n--- Robotomy ---\n";
	form = intern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form << '\n';
		chief.signForm(*form);
		chief.executeForm(*form);
		delete form;
	}

	std::cout << "\n--- Presidential pardon ---\n";
	form = intern.makeForm("presidential pardon", "Arthur Dent");
	if (form)
	{
		std::cout << *form << '\n';
		chief.signForm(*form);
		chief.executeForm(*form);
		delete form;
	}

	std::cout << "\n--- Unknown names ---\n";
	form = intern.makeForm("PresidentialPardonForm", "Arthur Dent");
	std::cout << "Null pointer: " << (form == 0) << '\n';
	delete form;

	form = intern.makeForm("", "Nobody");
	std::cout << "Null pointer: " << (form == 0) << '\n';
	delete form;

	std::cout << "\n--- Copy and assignment ---\n";
	Intern copy(intern);
	Intern assigned;

	assigned = copy;
	form = assigned.makeForm("presidential pardon", "Ford Prefect");
	if (form)
	{
		chief.signForm(*form);
		chief.executeForm(*form);
		delete form;
	}

	return 0;
}