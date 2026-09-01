/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 01:39:15 by mzangaro          #+#    #+#             */
/*   Updated: 2026/09/01 01:40:17 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_templates[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource	&operator=(const MateriaSource &other);
	virtual ~MateriaSource();

	virtual void		learnMateria(AMateria *m);
	virtual AMateria	*createMateria(std::string const &type);
};

#endif