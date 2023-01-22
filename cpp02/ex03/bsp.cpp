/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:56:51 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/21 21:37:15 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float	getTriangleArea(Point const p1, Point const p2, Point const p3)
{
	float	area;

	area = (p1.getX().toFloat() * (p2.getY().toFloat() - p3.getY().toFloat())
		+ p2.getX().toFloat() * (p3.getY().toFloat() - p1.getY().toFloat())
		+ p3.getX().toFloat() * (p1.getY().toFloat() - p2.getY().toFloat()))
		/ 2;
	area = area < 0 ? area * -1 : area;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	triangle_area;
	float	area1;
	float	area2;
	float	area3;

	triangle_area = getTriangleArea(a, b, c);
	area1 = getTriangleArea(point, a, b);
	area2 = getTriangleArea(point, b, c);
	area3 = getTriangleArea(point, a, c);
	if (triangle_area == 0 || area1 == 0 || area2 == 0 || area3 == 0)
		return (false);
	if (triangle_area == (area1 + area2 + area3))
		return (true);
	return (false);
}
