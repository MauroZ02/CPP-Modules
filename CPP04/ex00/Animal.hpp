/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:58:40 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/26 01:10:49 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
	std::string	type;
public:
	Animal();
	Animal(const Animal &other);
	Animal	&operator=(const Animal &other);
	virtual ~Animal();

	const std::string			&getType() const;
	virtual void		makeSound() const;
};

#endif