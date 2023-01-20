/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:52:46 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/19 22:27:35 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
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
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << __FUNCTION__ << " member function called" << std::endl;
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << __FUNCTION__ << " member function called" << std::endl;
	this->rawBits = raw;
}
