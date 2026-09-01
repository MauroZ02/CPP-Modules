/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:55:48 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/21 04:17:11 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float nFloat);
		Fixed(const Fixed &other);

		~Fixed();
		Fixed	&operator=(const Fixed &other);

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);


#endif