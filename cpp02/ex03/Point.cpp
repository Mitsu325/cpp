/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:39:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/21 21:24:06 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): x(0), y(0)
{}

Point::Point(float const number1, float const number2): x(number1), y(number2)
{}

Point::~Point(void)
{}

Point::Point(Point const &point)
{
	*this = point;
	return ;
}

Point&	Point::operator=(Point const &point)
{
	if (this != &point)
	{
		(Fixed &) this->x = point.getX();
		(Fixed &) this->y = point.getY();
	}
	return (*this);
}

const Fixed&	Point::getX(void) const
{
	return (this->x);
}

const Fixed&	Point::getY(void) const
{
	return (this->y);
}
