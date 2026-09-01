/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:43:34 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/19 16:00:58 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

Weapon::Weapon(std::string type)
		: type(type)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType() const
{
	return (type);
}

void	Weapon::setType(std::string type)
{
	Weapon::type = type;
}