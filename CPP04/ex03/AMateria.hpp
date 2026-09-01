/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:21:49 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/30 15:03:42 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class ICharacter;

class AMateria
{
protected:
						std::string	type;
public:
						AMateria();
						AMateria(std::string const & type);
						AMateria(const AMateria &other);
			AMateria	&operator=(const AMateria &other);
			virtual		~AMateria();
	
	std::string const	&getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void 		use(ICharacter& target);
};

#endif
