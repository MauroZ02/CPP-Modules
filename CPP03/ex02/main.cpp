/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:00 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/23 15:35:16 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n--- BASIC TESTS ---" << std::endl;

	FragTrap	messi("Messi");

	messi.attack("CR7");
	messi.takeDamage(4);
	messi.beRepaired(2);
	messi.highFivesGuys();

	std::cout << "\n--- COPY CONSTRUCTOR ---" << std::endl;

	FragTrap	copy(messi);

	copy.attack("Neymar");

	std::cout << "\n--- COPY ASSIGNMENT ---" << std::endl;

	FragTrap	ronaldo("Ronaldo");

	ronaldo = messi;
	ronaldo.attack("Mbappe");

	std::cout << "\n--- NO ENERGY ---" << std::endl;

	FragTrap	tired("Tired");
	int			i;

	i = 0;
	while (i < 100)
	{
		tired.attack("Target");
		i++;
	}
	tired.attack("Target");
	tired.beRepaired(5);

	std::cout << "\n--- NO HIT POINTS ---" << std::endl;

	FragTrap	dead("Dead");

	dead.takeDamage(100);
	dead.attack("Target");
	dead.beRepaired(5);

	std::cout << "\n--- DESTRUCTORS ---" << std::endl;

	return (0);
}