/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:29:51 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/26 01:38:16 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &other);
	Dog	&operator=(const Dog &other);
	virtual ~Dog();

	virtual void	makeSound() const;
};

#endif