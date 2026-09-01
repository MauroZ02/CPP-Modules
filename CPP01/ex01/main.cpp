/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 01:13:10 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/19 01:53:35 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

int	main(void)
{
	Zombie	*horde;
	int		i = 0;

	horde = zombieHorde(3, "Mauro");
	
	while (i < 3)
	{
		horde[i].announce();
		i++;
	}

	delete[] horde;
	return 0;
}