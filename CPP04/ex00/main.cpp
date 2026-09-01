/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 02:07:15 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/26 02:18:51 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int	main(void)
{
	const Animal	*animal = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	cat->makeSound();
	dog->makeSound();
	animal->makeSound();

	delete cat;
	delete dog;
	delete animal;

	const WrongAnimal	*wrongAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();

	delete wrongCat;
	delete wrongAnimal;

	WrongCat	directWrongCat;
	directWrongCat.makeSound();

	Dog	dog1;
	Dog	dog2(dog1);
	Dog	dog3;

	dog3 = dog1;

	return (0);
}
