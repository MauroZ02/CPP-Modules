/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 13:56:42 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/18 15:15:07 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

Zombie	*newZombie( std::string name )
{
	Zombie	*zombie;

	zombie = new Zombie(name);
	return (zombie);
}
