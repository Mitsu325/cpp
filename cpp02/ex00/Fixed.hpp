/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:51:47 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/19 22:09:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H

# include <iostream>

class Fixed
{
	private:
		int					rawBits;
		static const int	frac_bits;

	public:
		Fixed(void);
		~Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed&	operator=(Fixed const &fixed);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
