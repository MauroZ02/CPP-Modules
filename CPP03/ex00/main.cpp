/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:00 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/22 02:04:57 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n--- BASIC TESTS ---" << std::endl;

	ClapTrap	messi("Messi");

	messi.attack("CR7");
	messi.takeDamage(4);
	messi.beRepaired(2);

	std::cout << "\n--- COPY CONSTRUCTOR ---" << std::endl;

	ClapTrap	copy(messi);

	copy.attack("Neymar");

	std::cout << "\n--- COPY ASSIGNMENT ---" << std::endl;

	ClapTrap	ronaldo("Ronaldo");

	ronaldo = messi;
	ronaldo.attack("Mbappe");

	std::cout << "\n--- NO ENERGY ---" << std::endl;

	ClapTrap	tired("Tired");
	int			i;

	i = 0;
	while (i < 10)
	{
		tired.attack("Target");
		i++;
	}
	tired.attack("Target");
	tired.beRepaired(5);

	std::cout << "\n--- NO HIT POINTS ---" << std::endl;

	ClapTrap	dead("Dead");

	dead.takeDamage(100);
	dead.attack("Target");
	dead.beRepaired(5);

	std::cout << "\n--- DESTRUCTORS ---" << std::endl;

	return (0);
}