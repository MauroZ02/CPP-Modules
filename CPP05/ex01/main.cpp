/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:11:02 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/13 00:45:16 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Constructors ---\n";
	{
		Form a;
		Form b("Contract", 50, 25);
		Form c(b);
		Form highest("Highest", 1, 1);
		Form lowest("Lowest", 150, 150);

		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << c << '\n';
		std::cout << highest << '\n';
		std::cout << lowest << '\n';
	}

	std::cout << "\n--- Invalid grades ---\n";
	try
	{
		Form a("Contract", 0, 25);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Form a("Contract", 151, 25);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Form a("Contract", 50, 0);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	try
	{
		Form a("Contract", 50, 151);
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "\n--- Signing ---\n";
	{
		const Bureaucrat junior("Junior", 51);
		const Bureaucrat equal("Equal", 50);
		const Bureaucrat senior("Senior", 49);
		Form a("Contract", 50, 25);
		Form b("Request", 50, 25);

		std::cout << a << '\n';

		junior.signForm(a);
		std::cout << a << '\n';

		equal.signForm(a);
		std::cout << a << '\n';

		senior.signForm(b);
		std::cout << b << '\n';
	}

	std::cout << "\n--- Direct signing ---\n";
	{
		Bureaucrat junior("Junior", 100);
		Bureaucrat senior("Senior", 1);
		Form a("Contract", 50, 25);

		try
		{
			a.beSigned(junior);
		}
		catch (const Form::GradeTooLowException &e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << a << '\n';

		a.beSigned(senior);
		std::cout << a << '\n';
	}

	std::cout << "\n--- Copy and assignment ---\n";
	{
		Bureaucrat signer("Mauro", 1);
		Form original("Original", 50, 25);

		signer.signForm(original);
		Form copy(original);

		Form target("Target", 100, 75);
		std::cout << target << '\n';

		target = original;

		std::cout << original << '\n';
		std::cout << copy << '\n';
		std::cout << target << '\n';

		Form unsignedForm("Unsigned", 150, 150);

		original = unsignedForm;

		std::cout << original << '\n';
		std::cout << copy << '\n';
		std::cout << target << '\n';
	}

	return 0;
}