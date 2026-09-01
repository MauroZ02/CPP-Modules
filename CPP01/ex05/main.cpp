/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 17:07:54 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/20 19:38:07 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	input;

	std::cout << "Introduce: <DEBUG> <INFO> <WARNING> <ERROR> <ALL>" << std::endl;
	std::cout << "> " ;
	std::cin >> input;

	if (input == "ALL")
	{
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		return 0;
	}
	harl.complain(input);
	return 0;
}