/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 15:39:38 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/30 15:54:11 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice()
	: AMateria("ice")
{
}

Ice::Ice(const Ice &other)
	: AMateria(other)
{
}

Ice	&Ice::operator=(const Ice &other)
{
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice::~Ice()
{
}

AMateria	*Ice::clone() const
{
	return (new Ice(*this)); //allocate a new Ice on the heap using the Ice copy constructor
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}