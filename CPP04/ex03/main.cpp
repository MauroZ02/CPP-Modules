/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 01:21:11 by mzangaro          #+#    #+#             */
/*   Updated: 2026/09/01 02:06:07 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <iostream>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
}


// int	main(void)
// {
// 	IMateriaSource	*src;
// 	ICharacter		*me;
// 	ICharacter		*bob;
// 	AMateria		*tmp;

// 	std::cout << "\n--- SUBJECT TEST ---\n" << std::endl;

// 	src = new MateriaSource();

// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());

// 	me = new Character("me");
// 	bob = new Character("bob");

// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);

// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);

// 	me->use(0, *bob);
// 	me->use(1, *bob);

// 	std::cout << "\n--- UNKNOWN MATERIA ---\n" << std::endl;

// 	tmp = src->createMateria("fire");
// 	if (tmp == NULL)
// 		std::cout << "Unknown materia type" << std::endl;

// 	std::cout << "\n--- UNEQUIP TEST ---\n" << std::endl;

// 	AMateria	*dropped;

// 	dropped = src->createMateria("ice");
// 	me->equip(dropped);

// 	me->use(2, *bob);
// 	me->unequip(2);
// 	me->use(2, *bob);

// 	delete dropped;

// 	std::cout << "\n--- CHARACTER DEEP COPY ---\n" << std::endl;

// 	Character	original("original");

// 	tmp = src->createMateria("ice");
// 	original.equip(tmp);

// 	tmp = src->createMateria("cure");
// 	original.equip(tmp);

// 	Character	copy(original);

// 	original.use(0, *bob);
// 	original.use(1, *bob);

// 	copy.use(0, *bob);
// 	copy.use(1, *bob);

// 	Character	a("a");
// 	Character	b("b");
	
// 	tmp = src->createMateria("ice");
// 	a.equip(tmp);
	
// 	tmp = src->createMateria("cure");
// 	b.equip(tmp);
	
// 	b = a;
	
// 	a.use(0, *bob);
// 	b.use(0, *bob);

// 	MateriaSource	source1;

// 	source1.learnMateria(new Ice());
// 	source1.learnMateria(new Cure());
	
// 	MateriaSource	source2(source1);
	
// 	AMateria	*m;
	
// 	m = source2.createMateria("ice");
// 	delete m;
	
// 	m = source2.createMateria("cure");
// 	delete m;


// 	std::cout << "\n--- FULL INVENTORY ---\n" << std::endl;

// 	Character	full("full");
// 	AMateria	*extra;

// 	tmp = src->createMateria("ice");
// 	full.equip(tmp);
// 	tmp = src->createMateria("cure");
// 	full.equip(tmp);
// 	tmp = src->createMateria("ice");
// 	full.equip(tmp);
// 	tmp = src->createMateria("cure");
// 	full.equip(tmp);

// 	extra = src->createMateria("ice");
// 	full.equip(extra);

// 	// Inventory was already full, so Character did not take ownership.
// 	delete extra;

// 	full.use(0, *bob);
// 	full.use(1, *bob);
// 	full.use(2, *bob);
// 	full.use(3, *bob);

// 	std::cout << "\n--- INVALID SLOTS ---\n" << std::endl;

// 	full.use(-1, *bob);
// 	full.use(4, *bob);
// 	full.unequip(-1);
// 	full.unequip(4);

// 	delete bob;
// 	delete me;
// 	delete src;

// 	return (0);
// }