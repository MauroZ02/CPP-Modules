/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:15:26 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/19 16:40:31 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
		: name(name), weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	if (weapon != NULL)
	{
		std::cout << name << " attacks with their " << weapon->getType();
		std::cout << std::endl;
	}
}

void	HumanB::setWeapon(Weapon &weapon)
{
	HumanB::weapon = &weapon;
}