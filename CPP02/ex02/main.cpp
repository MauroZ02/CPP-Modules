/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 00:39:55 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/21 05:38:13 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
/*
int	main(void)
{
	Fixed	a(1.5f);
	Fixed	b(2.25f);

	std::cout << "=== VALUES ===" << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "\n=== COMPARISONS ===" << std::endl;
	std::cout << "a > b  : " << (a > b) << std::endl;
	std::cout << "a < b  : " << (a < b) << std::endl;
	std::cout << "a >= b : " << (a >= b) << std::endl;
	std::cout << "a <= b : " << (a <= b) << std::endl;
	std::cout << "a == b : " << (a == b) << std::endl;
	std::cout << "a != b : " << (a != b) << std::endl;

	std::cout << "\n=== ARITHMETIC ===" << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b = " << a - b << std::endl;
	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;

	Fixed	c;

	std::cout << "\n=== INCREMENT ===" << std::endl;
	std::cout << "c       = " << c << std::endl;
	std::cout << "++c     = " << ++c << std::endl;
	std::cout << "c       = " << c << std::endl;
	std::cout << "c++     = " << c++ << std::endl;
	std::cout << "c       = " << c << std::endl;

	std::cout << "\n=== DECREMENT ===" << std::endl;
	std::cout << "--c     = " << --c << std::endl;
	std::cout << "c       = " << c << std::endl;
	std::cout << "c--     = " << c-- << std::endl;
	std::cout << "c       = " << c << std::endl;

	Fixed	d(3);
	Fixed	e(7);

	std::cout << "\n=== MIN / MAX ===" << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "e = " << e << std::endl;
	std::cout << "min(d, e) = " << Fixed::min(d, e) << std::endl;
	std::cout << "max(d, e) = " << Fixed::max(d, e) << std::endl;

	const Fixed	f(4);
	const Fixed	g(6);

	std::cout << "\n=== CONST MIN / MAX ===" << std::endl;
	std::cout << "f = " << f << std::endl;
	std::cout << "g = " << g << std::endl;
	std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
	std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;

	std::cout << "\n=== CONVERSIONS ===" << std::endl;
	std::cout << "a as float = " << a.toFloat() << std::endl;
	std::cout << "a as int   = " << a.toInt() << std::endl;

	std::cout << "\n=== RAW BITS ===" << std::endl;
	std::cout << "a raw = " << a.getRawBits() << std::endl;
	a.setRawBits(256);
	std::cout << "after setRawBits(256), a = " << a << std::endl;
	std::cout << "a raw = " << a.getRawBits() << std::endl;

	return (0);
}
*/