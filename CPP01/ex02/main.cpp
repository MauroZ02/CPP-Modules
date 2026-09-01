/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 15:07:17 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/19 15:14:02 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string variable = "HI THIS IS BRAIN";
	std::string *stringPTR = &variable; //a pointer is an object that stores an address
	std::string &stringREF = variable; // a reference is an alias for an existing object

	std::cout << "Memory address of the string 'variable': ";
	std::cout << &variable << std::endl; 
	std::cout << "Memory address held by 'stringPTR'     : ";
	std::cout << stringPTR << std::endl; 
	std::cout << "Memory address held by 'stringREF'     : ";
	std::cout << &stringREF << std::endl; 
	std::cout << "The value of the string 'variable'     : ";
	std::cout << variable << std::endl; 
	std::cout << "The value pointed to by stringPTR'     : ";
	std::cout << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF'     : ";
	std::cout << stringREF << std::endl;
}