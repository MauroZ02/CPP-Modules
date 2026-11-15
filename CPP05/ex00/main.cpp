/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 19:11:02 by mzangaro          #+#    #+#             */
/*   Updated: 2026/11/12 23:05:40 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "--- Constructors ---\n";
	{
		Bureaucrat a;
		Bureaucrat b("Mauro", 42);
		Bureaucrat c(b);

		std::cout << a << '\n';
		std::cout << b << '\n';
		std::cout << c << '\n';
	}

	std::cout << "\n--- Assignment ---\n";
	{
		Bureaucrat a("Alice", 10);
		Bureaucrat b("Bob", 50);

		b = a;
		std::cout << a << '\n';
		std::cout << b << '\n';

		b.decrementGrade();
		std::cout << a << '\n';
		std::cout << b << '\n';
	}

	std::cout << "\n--- Grade changes ---\n";
	{
		Bureaucrat a("Mauro", 42);

		std::cout << a << '\n';
		a.incrementGrade();
		std::cout << a << '\n';
		a.decrementGrade();
		std::cout << a << '\n';
	}

	std::cout << "\n--- Invalid grades ---\n";
	try
	{
		Bureaucrat a("Alice", 0);
		std::cout << a << '\n';
	}
	catch (const std::exception &e)		//the program can access the object &e 
	{									//-which is (TooHigh/TooLow)Exception-
		std::cout << e.what() << '\n';	//because is declared as inherited from std::exception
	}

	try
	{
		Bureaucrat a("Bob", 151);
		std::cout << a << '\n';
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << "\n--- Highest grade ---\n";
	{
		Bureaucrat a("Alice", 2);

		a.incrementGrade();
		std::cout << a << '\n';
		try
		{
			a.incrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << a << '\n';
	}

	std::cout << "\n--- Lowest grade ---\n";
	{
		Bureaucrat a("Bob", 149);

		a.decrementGrade();
		std::cout << a << '\n';
		try
		{
			a.decrementGrade();
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << '\n';
		}
		std::cout << a << '\n';
	}

	return 0;
}