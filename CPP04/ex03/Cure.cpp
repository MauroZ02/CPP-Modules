/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:57:18 by mzangaro          #+#    #+#             */
/*   Updated: 2026/09/01 01:33:44 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure()
	: AMateria("cure")
{
}

Cure::Cure(const Cure &other)
	: AMateria(other)
{
}

Cure	&Cure::operator=(const Cure &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure()
{
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this)); //allocate a new Cure on the heap using the Cure copy constructor
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}