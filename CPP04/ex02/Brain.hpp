/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 15:20:18 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/29 16:00:52 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class	Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain	&operator=(const Brain &other);
	~Brain();

	void				setIdea(int i, const std::string &idea);
	const std::string	&getIdea(int i) const;
};

#endif