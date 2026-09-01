/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 01:49:17 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/29 16:18:40 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class	Cat : public Animal
{
private:
	Brain	*brain;
public:
	Cat();
	Cat(const Cat &other);
	Cat	&operator=(const Cat &other);
	virtual ~Cat();

	virtual void	makeSound() const;
	void				setIdea(int i, const std::string &idea);
	const std::string	&getIdea(int i) const;
};

#endif