/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 20:10:16 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/14 20:37:38 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static void testForm(AForm &form, int signGrade, int executeGrade)
{
	Bureaucrat chief("Chief", 1);
	Bureaucrat junior("Junior", signGrade + 1);
	Bureaucrat signer("Signer", signGrade);
	Bureaucrat executor("Executor", executeGrade + 1);

	std::cout << form << '\n';

	chief.executeForm(form);

	junior.signForm(form);
	std::cout << form << '\n';

	signer.signForm(form);
	std::cout << form << '\n';

	executor.executeForm(form);
	executor.incrementGrade();
	executor.executeForm(form);
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL))); //initialisation of the random generator

	std::cout << "--- Default constructors ---\n";
	{
		ShrubberyCreationForm shrubbery;
		RobotomyRequestForm robotomy;
		PresidentialPardonForm pardon;

		std::cout << shrubbery << '\n';
		std::cout << robotomy << '\n';
		std::cout << pardon << '\n';
	}

	std::cout << "\n--- Shrubbery ---\n";
	{
		ShrubberyCreationForm form("garden"); //form's target

		testForm(form, 145, 137);
	}

	std::cout << "\n--- Robotomy ---\n";
	{
		RobotomyRequestForm form("Bender");

		testForm(form, 72, 45);
	}

	std::cout << "\n--- Presidential pardon ---\n";
	{
		PresidentialPardonForm form("Arthur Dent");

		testForm(form, 25, 5);
	}

	std::cout << "\n--- Repeated robotomy ---\n";
	{
		Bureaucrat chief("Chief", 1);
		RobotomyRequestForm form("Marvin");
		int i = 0;

		chief.signForm(form);
		while (i < 10)
		{
			chief.executeForm(form);
			i++;
		}
	}

	std::cout << "\n--- Copy and assignment ---\n";
	{
		Bureaucrat chief("Chief", 1);
		ShrubberyCreationForm original("original");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		chief.signForm(original);
		chief.signForm(robotomy);
		chief.signForm(pardon);

		ShrubberyCreationForm shrubberyCopy(original);
		RobotomyRequestForm robotomyCopy(robotomy);
		PresidentialPardonForm pardonCopy(pardon);

		ShrubberyCreationForm shrubberyTarget("old");
		RobotomyRequestForm robotomyTarget("old");
		PresidentialPardonForm pardonTarget("old");

		shrubberyTarget = shrubberyCopy;
		robotomyTarget = robotomyCopy;
		pardonTarget = pardonCopy;

		ShrubberyCreationForm unsignedForm("replacement");
		original = unsignedForm;

		std::cout << original << '\n';
		std::cout << shrubberyCopy << '\n';
		std::cout << shrubberyTarget << '\n';
		std::cout << robotomyCopy << '\n';
		std::cout << robotomyTarget << '\n';
		std::cout << pardonCopy << '\n';
		std::cout << pardonTarget << '\n';

		chief.executeForm(shrubberyCopy);
		chief.executeForm(shrubberyTarget);
		chief.executeForm(robotomyTarget);
		chief.executeForm(pardonTarget);
	}

	std::cout << "\n--- File error ---\n";
	{
		Bureaucrat chief("Chief", 1);
		ShrubberyCreationForm form(
			"cpp05_nonexistent_directory/tree");

		chief.signForm(form);
		chief.executeForm(form);
	}

	std::cout << "\n--- Direct execution ---\n";
	{
		Bureaucrat chief("Chief", 1);
		PresidentialPardonForm form("Ford Prefect");

		try
		{
			form.execute(chief);
		}
		catch (const AForm::NotSignedException &e)
		{
			std::cout << e.what() << '\n';
		}

		chief.signForm(form);
		const AForm &base = form;
		base.execute(chief);
	}

	std::cout << "\n--- Deletion through base pointer ---\n";
	{
		AForm *form = new PresidentialPardonForm("Trillian");

		std::cout << *form << '\n';
		delete form;
	}

	return 0;
}