/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:05:58 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/15 01:52:26 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>

PhoneBook::PhoneBook() //Constructor
	:	_contact_count(0), _next_index(0) //a way to initialise directly
{
	// if done here would be like: 
	// _contact_count exists, initialise it to 0;
}

std::string	PhoneBook::getField(std::string prompt)
{
	std::string	input;

	while (input.empty()) //Initially any std::string is empty
	{
		std::cout << prompt << std::flush;
		if (!std::getline(std::cin, input)) // reads an entire line from terminal
			return ("");					// and stores it in input
		if (input.empty())
			std::cout << "\033[1A\033[2K\r";
	}
	return (input);
}

void	PhoneBook::addContact()
{
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	
	std::cout << "===========================================" << std::endl;
	std::cout << "                ADD CONTACT                " << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << std::endl;
	
	first_name = getField("First Name: ");
	if (!std::cin)
		return;
	last_name = getField("Last Name: ");
	if (!std::cin)
		return;
	nickname = getField("Nickname: ");
	if (!std::cin)
		return;
	phone_number= getField("Phone number: ");
	if (!std::cin)
		return;
	darkest_secret = getField("Darkest secret: ");
	if (!std::cin)
		return;

	_contacts[_next_index].setContact(first_name, last_name, nickname,
										phone_number, darkest_secret);

	if (_contact_count < 8)
		_contact_count++;

	_next_index = (_next_index + 1) % 8;
	std::cout << std::endl;
	std::cout << "Contact added successfully.";
}

std::string	PhoneBook::formatField(std::string field) const
{
	if (field.length() > 10)
		return (field.substr(0,9) + "."); //take from char 0 until 9, then add '.'
	return (field);
}

void	PhoneBook::searchContact()
{
	int			i = 0;
	int			num;
	std::string	input;

	std::cout << "===========================================" << std::endl;
	std::cout << "               SEARCH CONTACT              " << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << std::endl;

	if (_contact_count == 0)
	{
		// std::cout << std::endl;
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	while (i < _contact_count)
	{
		std::cout << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::setw(10) << formatField(_contacts[i].getFirstName());
		std::cout << "|";
		std::cout << std::setw(10) << formatField(_contacts[i].getLastName());
		std::cout << "|";
		std::cout << std::setw(10) << formatField(_contacts[i].getNickname());
		std::cout << std::endl;
		i++;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (input.length() != 1)
	{
		std::cout << std::endl;
		std::cout << "Invalid index." << std::endl;
		return;
	}
	if (input[0] >= '0' && input[0] <= '7')
	{
		num = input[0] - '0';
		if (num < _contact_count)
			_contacts[num].displayDetails();
		else
		{
			std::cout << std::endl;
			std::cout << "index contact doesn't exist." << std::endl;
		}
	}
	else
	{
		std::cout << std::endl;
		std::cout << "index contact must be between 0 and 7." << std::endl;
	}
	return;
}
