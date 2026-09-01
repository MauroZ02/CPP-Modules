/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 14:36:51 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/18 14:46:56 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie
{
private:
	std::string	name; //variable inside the object
public:
	Zombie( std::string name ); //parameter that the constructor receives
	~Zombie( void );
	void	announce ( void );
};

Zombie*	newZombie( std::string name );
void	randomChump ( std::string name );


#endif