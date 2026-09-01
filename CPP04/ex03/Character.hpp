/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 00:55:29 by mzangaro          #+#    #+#             */
/*   Updated: 2026/09/01 01:18:00 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include <string>

class	Character: public ICharacter
{
private:
	std::string _name;
	AMateria *_inventory[4];

public:
	Character();
	Character(std::string const &name);
	Character(const Character &other);
	Character	&operator=(const Character &other);
	virtual ~Character();
	
	std::string const	&getName() const;
	void				equip(AMateria *m);
	void				unequip(int idx);
	void				use(int idx, ICharacter &target);
};

#endif