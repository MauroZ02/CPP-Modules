/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 16:57:52 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/21 19:20:20 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &other);
	Point	&operator=(const Point &other);
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif