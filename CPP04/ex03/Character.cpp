/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 00:58:38 by mzangaro          #+#    #+#             */
/*   Updated: 2026/09/01 01:56:48 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character()
	: _name("")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string const &name)
	: _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character &other)
	: _name(other._name)
{
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character	&Character::operator=(const Character &other)
{
	int i;
	if (this != &other)
	{
		for (i = 0; i < 4; i++)
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
		_name = other._name;
		for (i = 0; i < 4; i++)
		{
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}


std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx] == NULL)
		return ;
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx] == NULL)
		return ;
	_inventory[idx]->use(target);
}