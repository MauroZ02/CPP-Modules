/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 00:58:40 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/30 01:08:17 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
protected:
	std::string	type;
public:
	AAnimal();
	AAnimal(const AAnimal &other);
	AAnimal	&operator=(const AAnimal &other);
	virtual ~AAnimal();

	const std::string			&getType() const;
	virtual void		makeSound() const = 0; // '= 0' makes this function pure virtual, 
											//    therefore, the entire class is Abstract
};

#endif