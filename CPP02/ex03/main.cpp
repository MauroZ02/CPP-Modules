/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 00:39:55 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/21 19:45:39 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int	main(void)
{
	Point	a(2.0f, 2.0f);
	Point	b(7.0f, 2.0f);
	Point	c(5.0f, 6.0f);
	Point	pInside(5.0f, 4.0f);
	Point	pOutside(8.0f, 4.0f);
	Point	pEdge(5.0f, 2.0f);
	Point	pVertex(5.0f, 6.0f);

	std::cout << std::boolalpha;

	std::cout << "Inside:  " << bsp(a, b, c, pInside) << std::endl;
	std::cout << "Outside: " << bsp(a, b, c, pOutside) << std::endl;
	std::cout << "Edge:    " << bsp(a, b, c, pEdge) << std::endl;
	std::cout << "Vertex:  " << bsp(a, b, c, pVertex) << std::endl;

	std::cout << "Inside with clockwise vertices: "
		<< bsp(a, c, b, pInside) << std::endl;

	return (0);
}