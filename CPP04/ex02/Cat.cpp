/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:50:17 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/30 01:15:41 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat()
		: AAnimal(), brain(new Brain())
{
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other)
		: AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "MeeEEeeOouUUUwwWW!" << std::endl;
}

void	Cat::setIdea(int i, const std::string &idea)
{
	brain->setIdea(i, idea);
}

const std::string	&Cat::getIdea(int i) const
{
	return (brain->getIdea(i));
}