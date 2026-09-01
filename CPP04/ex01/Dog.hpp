/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:29:51 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/29 16:13:16 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class	Dog : public Animal
{
private:
	Brain	*brain;
public:
	Dog();
	Dog(const Dog &other);
	Dog	&operator=(const Dog &other);
	virtual ~Dog();

	virtual void	makeSound() const;
	void				setIdea(int i, const std::string &idea);
	const std::string	&getIdea(int i) const;
};

#endif