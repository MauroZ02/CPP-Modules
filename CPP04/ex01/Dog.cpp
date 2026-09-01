/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:38:18 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/29 16:18:05 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
		: Animal(), brain(new Brain())
{
	type = "Dog";
	// brain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &other)
		: Animal(other), brain(new Brain(*other.brain))
{
	// brain = new Brain(*other.brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "WOUF WOUF WOUF!" << std::endl;
}

void	Dog::setIdea(int i, const std::string &idea)
{
	brain->setIdea(i, idea);
}

const std::string	&Dog::getIdea(int i) const
{
	return (brain->getIdea(i));
}