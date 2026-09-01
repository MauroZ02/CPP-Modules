/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:49:17 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/26 01:49:49 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &other);
	Cat	&operator=(const Cat &other);
	virtual ~Cat();

	virtual void	makeSound() const;
};

#endif