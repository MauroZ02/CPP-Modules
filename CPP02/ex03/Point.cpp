/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 17:13:41 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/21 20:02:04 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point()
		: _x(0), _y(0)
{
}

Point::Point(const float x, const float y)
		: _x(x), _y(y)
{
}

Point::Point(const Point &other)
		: _x(other._x), _y(other._y)
{
}

Point	&Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}

Point::~Point()
{
}
