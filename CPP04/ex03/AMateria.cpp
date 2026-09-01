/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 14:57:31 by mzangaro          #+#    #+#             */
/*   Updated: 2026/09/01 01:54:36 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#include <iostream>

AMateria::AMateria()
	: type("")
{
}

AMateria::AMateria(std::string const &type)
	: type(type)
{
}

AMateria::AMateria(const AMateria &other)
	: type(other.type)
{
}

AMateria	&AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria()
{
}

std::string const	&AMateria::getType() const
{
	return (type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}
