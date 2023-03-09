/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:52:46 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/21 21:24:38 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::frac_bits = 8;

Fixed::Fixed(void): rawBits(0)
{}

Fixed::Fixed(int const number)
{
	this->rawBits = number << this->frac_bits;
	return ;
}

Fixed::Fixed(float const number)
{
	this->rawBits = roundf(number * (1 << this->frac_bits));
	return ;
}

Fixed::~Fixed(void)
{}

Fixed::Fixed(Fixed const &fixed)
{
	*this = fixed;
	return ;
}

Fixed&	Fixed::operator=(Fixed const &fixed)
{
	if (this != &fixed)
	{
		this->rawBits = fixed.getRawBits();
	}
	return *this;
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->rawBits > fixed.getRawBits());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->rawBits >= fixed.getRawBits());
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->rawBits < fixed.getRawBits());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->rawBits <= fixed.getRawBits());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->rawBits == fixed.getRawBits());
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->rawBits != fixed.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed	temp;

	temp.setRawBits(this->getRawBits() + fixed.getRawBits());
	return (temp);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed	temp;

	temp.setRawBits(this->getRawBits() - fixed.getRawBits());
	return (temp);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed	temp;

	temp.setRawBits(this->toFloat() * fixed.getRawBits());
	return (temp);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed	temp;

	temp.setRawBits(this->getRawBits() / fixed.toFloat());
	return (temp);
}

Fixed&	Fixed::operator++(void)
{
	++this->rawBits;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp.setRawBits(this->rawBits++);
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	if ((this->rawBits - 1) > 0)
		--this->rawBits;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	if ((this->rawBits - 1) > 0)
		temp.setRawBits(this->rawBits--);
	else
		temp.setRawBits(this->rawBits);
	return (temp);
}

int	Fixed::getRawBits(void) const
{
	return this->rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float) this->rawBits / (1 << this->frac_bits));
}

int	Fixed::toInt(void) const
{
	return (this->rawBits >> this->frac_bits);
}

Fixed&	Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed const &	Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1.getRawBits() < num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed&	Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

Fixed const &	Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1.getRawBits() > num2.getRawBits())
		return (num1);
	return (num2);
}

std::ostream&	operator<<(std::ostream &stream, Fixed const &fixed_num)
{
	stream << fixed_num.toFloat();
	return (stream);
}
