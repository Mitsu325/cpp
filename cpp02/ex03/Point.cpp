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
{
	// std::cout << "Default constructor called" << std::endl;
	return ;
}

Point::Point(float const number1, float const number2): x(number1), y(number2)
{
	// std::cout << "Float constructor called" << std::endl;
	return ;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
	return ;
}

Point::Point(Point const &point)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = point;
	return ;
}

Point&	Point::operator=(Point const &point)
{
	(Fixed &) this->x = point.x;
	(Fixed &) this->y = point.y;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->x);
}

Fixed	Point::getY(void) const
{
	return (this->y);
}
