/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:03:34 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/21 19:19:44 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

static Fixed	sign(Point const &a, Point const &b, Point const &point)
{
	Fixed	res;
	res = ((b.getX() - a.getX()) * (point.getY() - a.getY()))
		- ((b.getY() - a.getY()) * (point.getX() - a.getX()));
	return (res);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ab;
	Fixed	bc;
	Fixed	ca;

	ab = sign(a, b, point);
	bc = sign(b, c, point);
	ca = sign(c, a, point);

	if (ab.toFloat() == 0 || bc.toFloat() == 0 || ca.toFloat() == 0)
		return (false);
	if (ab.toFloat() < 0 && bc.toFloat() < 0 && ca.toFloat() < 0)
		return (true);
	if (ab.toFloat() > 0 && bc.toFloat() > 0 && ca.toFloat() > 0)
		return (true);
	return (false);
}