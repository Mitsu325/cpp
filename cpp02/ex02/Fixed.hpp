/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:51:47 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/21 09:01:04 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int	rawBits;
		static const int	frac_bits = 8;

	public:
		Fixed(void);
		Fixed(int const number);
		Fixed(float const number);
		~Fixed(void);
		Fixed(Fixed const &fixed);
		Fixed&	operator=(Fixed const &fixed);
		bool	operator>(Fixed const &fixed);
		bool	operator>=(Fixed const &fixed);
		bool	operator<(Fixed const &fixed);
		bool	operator<=(Fixed const &fixed);
		bool	operator==(Fixed const &fixed);
		bool	operator!=(Fixed const &fixed);
		Fixed	operator+(Fixed const &fixed);
		Fixed	operator-(Fixed const &fixed);
		Fixed	operator*(Fixed const &fixed);
		Fixed	operator/(Fixed const &fixed);
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed&	min(Fixed &num1, Fixed &num2);
		static Fixed const &	min(Fixed const &num1, Fixed const &num2);
		static Fixed&	max(Fixed &num1, Fixed &num2);
		static Fixed const &	max(Fixed const &num1, Fixed const &num2);
};

std::ostream&	operator<<(std::ostream &stream, Fixed const &fixed_num);

#endif
