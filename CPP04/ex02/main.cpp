/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 02:07:15 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/30 01:09:04 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>

int	main(void)
{
	AAnimal	*animals[10];
	// AAnimal	animal;
	int		i;

	std::cout << "\n--- ANIMAL ARRAY ---\n" << std::endl;

	i = 0;
	while (i < 10)
	{
		if (i < 5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		i++;
	}

	std::cout << "\n--- SOUNDS ---\n" << std::endl;

	i = 0;
	while (i < 10)
	{
		animals[i]->makeSound();
		i++;
	}

	std::cout << "\n--- DELETING ANIMALS ---\n" << std::endl;

	i = 0;
	while (i < 10)
	{
		delete animals[i];
		i++;
	}

	std::cout << "\n--- DOG COPY CONSTRUCTOR ---\n" << std::endl;

	Dog	dog1;
	dog1.setIdea(0, "I want a bone");

	Dog	dog2(dog1);
	dog2.setIdea(0, "I want a ball");

	std::cout << "dog1: " << dog1.getIdea(0) << std::endl;
	std::cout << "dog2: " << dog2.getIdea(0) << std::endl;

	std::cout << "\n--- DOG ASSIGNMENT ---\n" << std::endl;

	Dog	dog3;
	dog1.setIdea(1, "I want to sleep");
	dog3 = dog1;
	dog3.setIdea(1, "I want to run");

	std::cout << "dog1: " << dog1.getIdea(1) << std::endl;
	std::cout << "dog3: " << dog3.getIdea(1) << std::endl;

	std::cout << "\n--- CAT COPY CONSTRUCTOR ---\n" << std::endl;

	Cat	cat1;
	cat1.setIdea(0, "I want some fish");

	Cat	cat2(cat1);
	cat2.setIdea(0, "I want to destroy the sofa");

	std::cout << "cat1: " << cat1.getIdea(0) << std::endl;
	std::cout << "cat2: " << cat2.getIdea(0) << std::endl;

	std::cout << "\n--- CAT ASSIGNMENT ---\n" << std::endl;

	Cat	cat3;
	cat1.setIdea(1, "I want to sleep");
	cat3 = cat1;
	cat3.setIdea(1, "I want to climb the curtains");

	std::cout << "cat1: " << cat1.getIdea(1) << std::endl;
	std::cout << "cat3: " << cat3.getIdea(1) << std::endl;

	return (0);
}