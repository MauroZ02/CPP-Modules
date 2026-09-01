/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:07:49 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/20 20:24:02 by mzangaro         ###   ########.fr       */
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
	typedef void(Harl::*harlFunction)(void);
	harlFunction	functions[4];
	std::string		levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int				i = 0;

	functions[0] = &Harl::debug;
	functions[1] = &Harl::info;
	functions[2] = &Harl::warning;
	functions[3] = &Harl::error;

	while (i < 4 && level != levels[i])
		i++;
	
	switch (i)
	{
		case 0:
		{
			(this->*functions[0])();
		}
		//fall through
		case 1:
		{
			(this->*functions[1])();
		}
		//fall through
		case 2:
		{
			(this->*functions[2])();
		}
		//fall through
		case 3:
		{
			(this->*functions[3])();
			break;
		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		}
	}
	return;
}
