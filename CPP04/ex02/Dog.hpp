/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:29:51 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/30 01:00:58 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class	Dog : public AAnimal
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