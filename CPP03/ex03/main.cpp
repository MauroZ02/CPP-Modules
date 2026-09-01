/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:00 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/24 01:12:36 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int	main(void)
{
	std::cout << "\n--- BASIC DIAMONDTRAP ---" << std::endl;

	DiamondTrap	messi("Messi");

	messi.whoAmI();
	messi.attack("CR7");
	messi.takeDamage(40);
	messi.beRepaired(10);

	std::cout << "\n--- INHERITED SPECIAL ABILITIES ---" << std::endl;

	messi.guardGate();
	messi.highFivesGuys();

	std::cout << "\n--- COPY CONSTRUCTOR ---" << std::endl;

	DiamondTrap	copy(messi);

	copy.whoAmI();
	copy.attack("Neymar");

	std::cout << "\n--- COPY ASSIGNMENT ---" << std::endl;

	DiamondTrap	ronaldo("Ronaldo");

	ronaldo = messi;
	ronaldo.whoAmI();
	ronaldo.attack("Mbappe");

	std::cout << "\n--- NO HIT POINTS ---" << std::endl;

	DiamondTrap	dead("Dead");

	dead.takeDamage(100);
	dead.attack("Target");
	dead.beRepaired(10);

	std::cout << "\n--- DESTRUCTORS ---" << std::endl;

	return (0);
}