/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:51:47 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/20 21:17:48 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					rawBits;
		static const int	frac_bits;

	public:
		Fixed(void);
		Fixed(int const number);
		Fixed(float const number);
		~Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed&	operator=(Fixed const &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream&	operator<<(std::ostream &stream, Fixed const &fixed_num);

#endif
