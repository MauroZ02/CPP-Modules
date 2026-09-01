/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 01:13:05 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/19 01:35:15 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
	std::string	name;

	public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce (void);
	void	setName(std::string name);
};

Zombie*	zombieHorde( int N, std::string name );

#endif