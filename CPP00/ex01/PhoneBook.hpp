/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:31:50 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/14 16:56:05 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
	Contact		_contacts[8];   // the eight contacts the PhoneBook must have
	int			_contact_count; // the count of the contacts already stored
	int			_next_index;    // an index to know which contact replace after max capacity
	std::string	formatField(std::string field) const;
	std::string	getField(std::string prompt);

	public:
	PhoneBook();             // Constructor: needed because we have some variables 
							 // to initialise (int, int). Unlike Contact.
	
	void	addContact();    // function ADD
	void	searchContact(); // function SEARCH

};

#endif