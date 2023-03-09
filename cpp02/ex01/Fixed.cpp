/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:52:46 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/20 21:34:32 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed(void): rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(int const number)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = number << Fixed::frac_bits;
	return ;
}

Fixed::Fixed(float const number)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(number * (1 << Fixed::frac_bits));
	return ;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
}

Fixed&	Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		this->rawBits = fixed.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (this->rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->rawBits / (1 << Fixed::frac_bits));
}

int	Fixed::toInt(void) const
{
	return (this->rawBits >> Fixed::frac_bits);
}

std::ostream&	operator<<(std::ostream &stream, Fixed const &fixed_num)
{
	stream << fixed_num.toFloat();
	return (stream);
}
