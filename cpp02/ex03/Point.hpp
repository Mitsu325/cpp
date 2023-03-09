/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:36:02 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/21 20:58:14 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef POINT_H

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point(void);
		Point(float const number1, float const number2);
		~Point(void);
		Point(Point const &point);
		Point&	operator=(Point const &point);

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
