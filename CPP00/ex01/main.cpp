/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/14 01:21:24 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/15 01:46:00 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

void	clearScreen()
{
	std::cout << "\033[2J\033[H";
}

void	waitForEnter()
{
	std::string	input;

	std::cout << std::endl;
	std::cout << "Press Enter to continue...";
	std::getline(std::cin, input);
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	input;

	while (1)
	{
		clearScreen();
		std::cout << "===========================================" << std::endl;
		std::cout << "                 PHONEBOOK                 " << std::endl;
		std::cout << "===========================================" << std::endl;
		std::cout << std::endl;
		std::cout << "ADD     Add a new contact" << std::endl;
		std::cout << "SEARCH  Search contacts" << std::endl;
		std::cout << "EXIT    Exit PhoneBook" << std::endl;
		std::cout << std::endl;
		std::cout << "> ";

		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
		{
			clearScreen();
			phonebook.addContact();
			waitForEnter();
		}
		else if (input == "SEARCH")
		{
			clearScreen();
			phonebook.searchContact();
			waitForEnter();
		}
		else if (input == "EXIT")
			break;
	}
	return (0);
}