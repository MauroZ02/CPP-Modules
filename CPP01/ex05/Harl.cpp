/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:07:49 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/20 20:07:17 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
	<< "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
	<< "You didn't put enough bacon in my burger! If you did, I wouldn't be "
	<< "asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
	<< "I've been coming for years, whereas you started working here just last month."
	<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	typedef void(Harl::*harlFunction)(void); //typedef is to create an alias. We assigned the name harlFunction
											 //to a member-function pointer of Harl that takes no args and returns void

	harlFunction	functions[4]; //now we created an array of 4 pointers to member functions inside Harl
	std::string		levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;
	
	for(int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();//Calling the member function stored in functions[i] on the current Harl object.
			return;
		}
	}
}