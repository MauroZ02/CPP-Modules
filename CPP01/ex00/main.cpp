/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:19:15 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/18 15:50:44 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(void)
{
	Zombie	*zombie;
	
	zombie = newZombie("Foo");
	zombie->announce();
	randomChump("Chump");

	delete zombie;

	return 0;
}