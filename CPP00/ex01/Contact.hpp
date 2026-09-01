/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 15:31:55 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/14 00:48:37 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

	public:
		void		setContact(std::string _first_name, std::string _last_name,
								std::string _nickname, std::string _phone_number,
								std::string _darkest_secret); // a big "Setter" that sets all the data at once

		std::string	getFirstName() const;   // a getter for Name
		std::string	getLastName() const;    // a getter for Last Name
		std::string	getNickname() const;    // a getter for Nick Name

		void		displayDetails() const; // prints all the data
};

#endif