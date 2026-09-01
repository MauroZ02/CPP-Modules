/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 22:55:48 by mzangaro          #+#    #+#             */
/*   Updated: 2026/08/21 00:47:19 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other); // copy constructor
		Fixed &operator=(const Fixed &other); // copy assignment operator
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif